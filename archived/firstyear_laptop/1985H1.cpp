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
const int maxN = 1e6+5;
string s[maxN];
int n, m, cha[maxN], sz[maxN], ml[maxN], mr[maxN], mu[maxN], md[maxN];
int row[maxN], col[maxN], rowD[maxN], rowU[maxN], colL[maxN], colR[maxN];
int srow[maxN], scol[maxN];
int getidx(int i, int j){
	assert((i-1)*m+j<=n*m&&(i-1)*m+j>0);
	return (i-1)*m+j;
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
		}
	}
	set<int> st;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j]=='.') continue;
			for (int k = 0; k < 4; k++){
				int ii = i+dx[k], jj = j+dy[k];
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
	for (int u: st){
		u = timcha(u);
		colL[ml[u]] += sz[u];
		colR[mr[u]] += sz[u];
		rowD[md[u]] += sz[u];
		rowU[mu[u]] += sz[u];
		for (int i = mu[u]; i <= md[u]; i++) row[i] += sz[u];
		for (int i = ml[u]; i <= mr[u]; i++) col[i] += sz[u];
		res = max(res,sz[u]);
	}
	
	for (int i = 1; i <= n; i++){
		int cur = row[i]+(m-srow[i]);
		if (i>1) cur += rowD[i-1];
		if (i<n) cur += rowU[i+1];
		res = max(res, cur);
//		cout << i << " row -> " << row[i] << "\n";
	}
	for (int i = 1; i <= m; i++){
		int cur = col[i]+(n-scol[i]);
		if (i>1) cur += colR[i-1];
		if (i<m) cur += colL[i+1];
		res = max(res, cur);
//		cout << i << " col -> " << cur << "\n";
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

