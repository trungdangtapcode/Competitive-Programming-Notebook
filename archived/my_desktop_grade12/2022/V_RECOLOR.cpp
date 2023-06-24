#include<bits/stdc++.h>

using namespace std;
int n, m, k, c[100005], f[100005];
vector<int> edge[100005];

void dfs(int u){
	f[u] = 1;
	for (int v: edge[u]){
		if (f[v]==0) dfs(v);
		f[u] = max(f[u],f[v]+1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		if (c[u]>c[v]) edge[u].push_back(v); //< or >
		else edge[v].push_back(u);
	}
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (f[i]==0) dfs(i);
		if (f[res]<f[i]) res = i;
	}
	cout << f[res] << " ";
	for (int i = 1; i <= n; i++) cout << f[i] << " ";
	cout << "\n";
	cout << res << " ";
	for (;f[res]>1;){
		for (int v: edge[res]) if (f[res]==f[v]+1){
			res = v;
			break;
		}
		cout << res << " "; 
	}
	
	return 0;
}
