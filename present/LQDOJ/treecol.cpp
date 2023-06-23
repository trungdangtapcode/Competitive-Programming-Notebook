#include<bits/stdc++.h>

using namespace std;

const int Nmax = 5005;

vector<int> edge[Nmax];
int n, f[Nmax][Nmax];

int dfs(int u, int p){
	// memset(f[u],0,sizeof(f[0]));
	for (int i = 0; i <= n; i++) f[u][i] = 0;
	int uleaf = 0;
	int cur = 0;
	if (edge[u].size()==1&&u!=1) return 1;
	for (int v: edge[u]) if (v!=p){
		int vleaf = dfs(v,u);
		for (int i = uleaf; i >= 0; i--) for (int j = vleaf; j >= 0; j--){
			f[u][i+j] = max(f[u][i+j],f[u][i]+f[v][j]+i*j);
		} 
		uleaf += vleaf;
		int tmp = 0;
		for (int i = 0; i <= vleaf; i++) tmp = max(tmp,f[v][i]+i);
		cur += tmp;
	}
	f[u][1] = max(f[u][1],cur);
	return uleaf;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	} 
	dfs(1,0);
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res,f[1][i]);
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ntest; cin >> ntest;
	while (ntest--) solve();
	return 0;
}