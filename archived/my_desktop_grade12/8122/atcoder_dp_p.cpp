#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
int f[100005][2], n;
vector<int> edge[100005];

void dfs(int p, int u){
	f[u][0] = f[u][1] = 1;
	for (int v: edge[u]) if (v!=p) dfs(u,v), f[u][0] = 1ll*f[u][0]*(f[v][0]+f[v][1])%mod, f[u][1] = 1ll*f[u][1]*f[v][0]%mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0,1);
	cout << (f[1][0]+f[1][1])%mod;
	
	return 0;
}
