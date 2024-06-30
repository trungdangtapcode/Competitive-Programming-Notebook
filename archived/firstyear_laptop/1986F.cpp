#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int par[maxN], low[maxN], num[maxN], n, m, sz[maxN];
vector<int> edge[maxN];
int timer = 0;
long long res = 0;
void dfs(int u, int p){
	par[u] = p;
	low[u] = num[u] = ++timer;
	sz[u] = 1;
	for (int v: edge[u]){
		if (v==p) continue;
		if (num[v]){
			low[u] = min(low[u],num[v]);
		} else {
			dfs(v,u);
			sz[u] += sz[v];
			low[u] = min(low[u],low[v]);
			if (low[v]>num[u]){
//				cout << u << ".." << v <<  " " << sz[v]*(1-sz[v]) << "\n";
				res = max(res,1ll*sz[v]*(n-sz[v]));
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	timer = res = 0;
	for (int i = 1; i <= n; i++) num[i] = 0;
	dfs(1,0);
	cout << 1ll*n*(n-1)/2-res << "\n";
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

