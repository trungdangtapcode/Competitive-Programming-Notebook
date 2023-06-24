#include<bits/stdc++.h>

using namespace std;
int d[100005], par[100005][20], n, m, cntE[100005], cntV[100005], pow2[100005];
const int p = 1e9+7;
vector<int> edge[100005];
void dfs(int p, int u){
	par[u][0] = p;
	d[u] = d[p] + 1;
	for (int i = 1; i < 20; i++) par[u][i] = par[par[u][i-1]][i-1];
	for (int v: edge[u]) if (v!=p){
		dfs(u,v);
	}
}
int lca(int u, int v){
	if (d[u]>d[v]) swap(u,v);
	for (int i = 19; i >= 0; i--) if (d[par[v][i]]>=d[u]) v = par[v][i];
	for (int i = 19; i >= 0; i--) if (par[u][i]!=par[v][i]) u = par[u][i], v = par[v][i];
	while (u!=v) u = par[u][0], v = par[v][0];
	return u;
}
void dfs2(int p, int u){
	for (int v: edge[u]) if (v!=p){
		dfs2(u,v);
		cntE[u] += cntE[v];
		cntV[u] += cntV[v];
	}
}

int main(){
	cin >> n >> m;
	pow2[0] = 1; 
	for (int i = 1; i <= m; i++) pow2[i] = 2*pow2[i-1]%p;
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0,1);
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		int z = lca(u,v);
		cntV[u]++, cntV[v]++, cntV[z]--, cntV[par[z][0]]--;
		cntE[u]++, cntE[v]++, cntE[z]-= 2;
	}
	dfs2(0,1);
	int res = 1; //root 1 + truong hop ko chon
	for (int i = 1; i <= n; i++){
		(res += pow2[cntV[i]]-pow2[cntE[i]])%=p;
		//V = E + 1 => ans = V - E (cac E nam xen ke vao E)
		//V bi cong trung se bi E tru ra (tree)
		//Inclusion-Exclusion
	}
	cout << (res+p)%p << "\n";
	
	return 0;
}
