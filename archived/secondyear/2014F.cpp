#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], c;
vector<int> edge[maxN];
int f[maxN][2];
void dfs(int u, int p = -1){
	f[u][0] = 0;
	f[u][1] = a[u];
	for (int v: edge[u]) if (v!=p){
		dfs(v,u);
		f[u][0] += max(f[v][0],f[v][1]);
		f[u][1] += max(f[v][0],f[v][1]-2*c);
	}
}

void solve(){
	cin >> n >> c;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++){
		int u, v; 
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1);
	cout << max(f[1][0],f[1][1]) << "\n";
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

