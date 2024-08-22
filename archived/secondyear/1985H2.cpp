#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;
ostream& operator<<(ostream& out, ii x){
	out << "(" << x.first << "," <<x.second << ")";
	return out;
}
void unpack(ii u, int& x, int& y){
	x = u.first;
	y = u.second;
}
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
const int maxN = 3e6+5;
string s[maxN];
int n, m, cha[maxN], sz[maxN], ml[maxN], mr[maxN], mu[maxN], md[maxN];
int row[maxN], col[maxN], UL[maxN], UR[maxN], DL[maxN], DR[maxN];
int srow[maxN], scol[maxN], pref[maxN];
int rowD[maxN], rowU[maxN], colL[maxN], colR[maxN];
int getidx(int i, int j){
//	assert((i-1)*m+j<=n*m&&(i-1)*m+j>0);
	return i*(m+2)+j;
}

int timcha(int u){
	return (u==cha[u]?u:cha[u]=timcha(cha[u]));
}
int timcha(int x, int y){
	return timcha(getidx(x,y));
}
bool hop(int ux, int uy, int vx, int vy){
	int u = getidx(ux,uy), v = getidx(vx,vy);
	u = timcha(u), v = timcha(v);
	if (u==v) return false;
	cha[v] = u;
	sz[u] += sz[v];
	ml[u] = min(ml[u],ml[v]);
	mr[u] = max(mr[u],mr[v]);
	mu[u] = min(mu[u],mu[v]);
	md[u] = max(md[u],md[v]);
	return true;
}

void solve(){
	cin >> n >> m;
//	idx.resize(n+2, vi(m+2));
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	for (int i = 1; i <= n; i++) 
		row[i] = rowU[i] = rowD[i] = srow[i] = 0;
	for (int i = 1; i <= m; i++) 
		col[i] = colL[i] = colR[i] = scol[i] = 0;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++){
		int id = getidx(i,j);
		pref[id] = 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int id = getidx(i,j);
			cha[id] = id;
			sz[id] = 1;
			ml[id] = j;
			mr[id] = j;
			mu[id] = i;
			md[id] = i;
			srow[i] += (s[i][j]=='#');
			scol[j] += (s[i][j]=='#');
			UL[id] = UR[id] = DL[id]= DR[id] = 0;
		}
	}
	set<int> st;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j]=='.') continue;
			for (int k = 0; k < 4; k++){
				int ii = i+dx[k], jj	 = j+dy[k];
				if (ii>n||ii<1||jj>m||jj<1) continue;
				if (s[ii][jj]!='#') continue;
//				cout << i << " " << j << " " << ii << " " << jj << "\n";
//				cout << timcha(i,j) << "\n";
				hop(i, j, ii, jj);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j]=='.') continue;
			st.insert(timcha(i,j));
		}
	}
	
//	for (auto it: st){
//		cout << it << " = " << mu[it] << ".." << md[it] << " " << ml[it] <<  ".." << mr[it] << "\n";
//	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++){
//			cout << timcha(i,j) << " ";
//		}
//		cout << "\n";
//	}

	int res = 0;
	for (int p: st){
		p = timcha(p);
//		UL[getidx(mu[u],ml[u])] += sz[u];
//		UR[getidx(mu[u],mr[u])] += sz[u];
//		DL[getidx(md[u],ml[u])] += sz[u];
//		DR[getidx(md[u],mr[u])] += sz[u];
//		colL[ml[u]] += sz[u];
//		colR[mr[u]] += sz[u];
//		rowD[md[u]] += sz[u];
//		rowU[mu[u]] += sz[u];
		int u = max(mu[p]-1,1), l = max(ml[p]-1,1), d = min(md[p]+1,n), r = min(mr[p]+1,m);
		for (int i = u; i <= d; i++) row[i] += sz[p];
		for (int i = l; i <= r; i++) col[i] += sz[p];
		pref[getidx(u,l)] += sz[p];
		pref[getidx(d+1,l)] -= sz[p];
		pref[getidx(u,r+1)] -= sz[p];
		pref[getidx(d+1,r+1)] += sz[p];
		res = max(res,sz[p]);
	}
		
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int cur = 0;
			pref[getidx(i,j)] += pref[getidx(i-1,j)]+pref[getidx(i,j-1)]-pref[getidx(i-1,j-1)];
//			cout << pref[getidx(i,j)] << " ";
			cur = col[j]+row[i]-pref[getidx(i,j)]+(m-srow[i]+n-scol[j]-(s[i][j]=='.'));
//			if (i>1) cur += rowD[i-1];
//			if (i<n) cur += rowU[i+1];
//			if (j>1) cur += colR[j-1];
//			if (j<m) cur += colL[j+1];
//			if (i>1&&j>1) cur -= DR[getidx(i-1,j-1)];
//			if (i>1&&j<m) cur -= DL[getidx(i-1,j+1)];
//			if (i<n&&j>1) cur -= UR[getidx(i+1,j-1)];
//			if (i<n&&j<m) cur -= UL[getidx(i+1,j+1)];
//			cout << cur << " ";
			res = max(res,cur);
		}
//		cout << "\n";
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}
