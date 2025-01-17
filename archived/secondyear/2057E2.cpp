#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int maxN = 405;
int cha[maxN], n, m, q;
int d[maxN][maxN][maxN], val[maxN];
vector<iii> edgelist;

int timcha(int u){
	return (u==cha[u]?u:cha[u]=timcha(cha[u]));
}
bool hop(int u, int v){
	u = timcha(u), v = timcha(v);
	if (u==v) return false;
	cha[v] = u;
	return true;
}

void solve(){
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cha[i] = i;
	edgelist.clear();
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= n; k++) d[k][i][j] = 0;
			d[0][i][j] = 1e9*(i!=j);
		}
	}
	for (int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		d[0][u][v] = d[0][v][u] = 1;
		edgelist.push_back({w,{u,v}});
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				d[0][i][j] = min(d[0][i][j],d[0][i][k]+d[0][k][j]);
			}
		}
	}
	sort(edgelist.begin(),edgelist.end());
	int ptr = 1;
	val[0] = -1e9;
	for (iii it: edgelist){
		int u = it.second.first, v = it.second.second, w = it.first;
		if (hop(u,v)){
			for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
				d[ptr][i][j] = min(d[ptr-1][i][j],d[ptr-1][i][u]+d[ptr-1][v][j]);
				d[ptr][i][j] = min(d[ptr][i][j],d[ptr-1][i][v]+d[ptr-1][u][j]);
			}
			val[ptr] = w;
			ptr++;
		}
	}
	while (q--){
		int u, v, k, l = 0, h = n, res = 0;
		cin >> u >> v >> k;
		while (l<=h){
			int m = (l+h)/2;
			if (d[m][u][v]<k){
				res = m;
				h = m-1;
			} else l = m+1;
		}
//		for (int i = 0; i <= n; i++) cout << d[i][u][v] << " "; cout << "\n";
//		cout << d[res][u][v] << "\n";
//		cout << res << "\n";
		cout << val[res] << " ";
	}
	cout << '\n';
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

