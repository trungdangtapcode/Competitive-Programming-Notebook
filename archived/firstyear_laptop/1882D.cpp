#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], f[maxN][20][2], f2[maxN][20][2], sz[maxN];
vector<int> edge[maxN];
void dfs(int u, int p){
	sz[u] = 1;
	for (int v: edge[u]) if (v!=p){
		dfs(v,u);
		int c = a[u]^a[v];
		for (int j = 0; j < 20; j++) f[u][j][0] += f[v][j][0], f[u][j][1] +=  f[v][j][1],
			f[u][j][(c>>j)&1] += sz[v];
		sz[u] += sz[v];
	}
	
}
void dfs2(int u, int p){
	int c = a[u]^a[p];
	if (p!=0) for (int j = 0; j < 20; j++) f[u][j][0] = f[p][j][0], f[u][j][1] = f[p][j][1],
		f[u][j][(c>>j)&1] -= sz[u], f[u][j][(c>>j)&1] += n-sz[u];
	for (int v: edge[u]) if (v!=p){
		dfs2(v,u);
	}
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		edge[i].clear();
		memset(f[i],0,sizeof(f[i]));
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) if (edge[i].size()==1){
		dfs(1,0);
		break;
	}
	for (int i = 1; i <= n; i++) if (edge[i].size()==1){
		dfs2(1,0);
		break;
	}
	for (int i = 1; i <= n; i++){
		int res = 0;
//		cout << i << ":\n";
//		for (int j = 0; j < 4; j++) cout << f[i][j][0] << " ";
//		cout << "\n";
//		for (int j = 0; j < 4; j++) cout << f[i][j][1] << " ";
//		cout << "\n";
		for (int j = 0; j < 20; j++) res += (1<<j)*(f[i][j][1]);
		cout << res << " ";
	}
	cout << "\n";
}

main(){
//	solve();
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}


/*
#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5;
int n, a[maxN], f[maxN][20][2], f2[maxN][20][2], sz[maxN];
vector<int> edge[maxN];
void dfs(int u, int p){
	bool check = 0;
	sz[u] = 1;
	for (int v: edge[u]) if (v!=p){
		check = 1;
		dfs(v,u);
		for (int j = 0; j < 20; j++) f[u][j][0] += f[v][j][0], f[u][j][1] +=  f[v][j][1];
		sz[u] += sz[v];
	}
	for (int j = 0; j < 20; j++){
		if ((1<<j)&a[u]) swap(f[u][j][0],f[u][j][1]);
		if (!check) f[u][j][(bool)((1<<j)&a[u])] += sz[u];
	}
}
void dfs2(int u, int p){
//	for (int j = 0; j < 20; j++) f2[u][j][]
	for (int v: edge[u]) if (v!=p){
		dfs2(v,u);
	}
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) if (edge[i].size()==1){
		dfs(1,0);
		break;
	}
	for (int i = 1; i <= n; i++){
		cout << i << ":\n";
		for (int j = 0; j < 4; j++) cout << f[i][j][0] << " ";
		cout << "\n";
		for (int j = 0; j < 4; j++) cout << f[i][j][1] << " ";
		cout << "\n";
	}
}

main(){
	solve();
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--) solve();
	
	return 0;
}
*/
