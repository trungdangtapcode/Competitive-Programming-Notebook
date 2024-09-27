#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int maxN = 2e5+5;
int n, a[maxN], m, h, f[2][maxN], g[2][maxN];
vector<ii> edge[maxN];
void dijkstra(int s, int d[2][maxN]){
	for (int i = 1; i <= n; i++){
		d[0][i] = d[1][i] = 1e15;
	}
	d[0][s] = 0;
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0,{0,s}});
	if (a[s]){
		d[1][s] = 0;
		pq.push({0,{1,s}});
	}
	while (pq.size()){
		auto it = pq.top(); pq.pop();
		int u = it.second.second, du = it.first, uhorse = it.second.first;
		if (du!=d[uhorse][u]) continue;
		for (auto it: edge[u]){
			int v = it.first, c = it.second, vhorse = uhorse;
			c = (uhorse?c/2:c);
			if (du+c<d[vhorse][v]){
				d[vhorse][v] = du+c;
				pq.push({d[vhorse][v],{vhorse,v}});
			}
			if (vhorse||!a[v]) continue;
			vhorse = 1;
			if (du+c<d[vhorse][v]){
				d[vhorse][v] = du+c;
				pq.push({d[vhorse][v],{vhorse,v}});
			}
		}
	}
}

void solve(){
	cin >> n >> m >> h;
	for (int i = 1; i <= n; i++) a[i] = 0, edge[i].clear();
	for (int i = 1; i <= h; i++){
		int p;
		cin >> p;
		a[p] = 1;
	}
	for (int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	dijkstra(1,f);
	dijkstra(n,g);
	int res = 1e15;
	for (int i = 1; i <= n; i++){
		res = min(res,max(
			min(f[0][i],f[1][i]),
			min(g[0][i],g[1][i])
		));
//		cout << i << " = "
//			<< f[0][i] << " " << f[1][i] << " "
//			<< g[0][i] << " " << g[1][i] << "\n";
	}
	cout << (res==1e15?-1:res) << "\n";
//	exit(0);
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

