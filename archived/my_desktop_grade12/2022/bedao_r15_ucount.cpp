#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5+5, mod = 1e9+7;
int n, m, k, par[maxN], f[maxN], g[maxN], inv[maxN], fact[maxN], d[maxN], rmq[maxN][20];
vector<int> edge[maxN];

void dfs1(int u, int p){
	d[u] = d[p] + 1;
	par[u] = p;
	rmq[u][0] = p;
	for (int i = 1; i < 20; i++) rmq[u][i] = rmq[rmq[u][i-1]][i-1];
	for (int v: edge[u]) if (v!=p){
		dfs1(v,u);
	}
}

int lca(int u, int v){
	if (d[u]>d[v]) swap(u,v);
	for (int i = 19; i >= 0; i--) if (d[rmq[v][i]]>=d[u]) v = rmq[v][i];
	for (int i = 19; i >= 0; i--) if (rmq[v][i]!=rmq[u][i]) u = rmq[u][i], v = rmq[v][i];
	while (u!=v) u = par[u], v = par[v];
	return u;
}
void dfs2(int u, int p){
	for (int v: edge[u]) if (v!=p){
		dfs2(v,u);
		f[u] += f[v];
		g[u] += g[v];
	}
}
int nCr(int n, int r){
	if (r<0||r>n) return 0;
	return 1ll*fact[n]*inv[n-r]%mod*inv[r]%mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	fact[0] = fact[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= 1e5; i++){
		fact[i] = 1ll*fact[i-1]*i%mod;
		inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
	}
	for (int i = 2; i <= 1e5; i++){
		inv[i] = 1ll*inv[i-1]*inv[i]%mod;
	}
	
	cin >> n >> m >> k;
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	for (int i = 0, u, v, z; i < m; i++){
		cin >> u >> v;
		z = lca(u,v);
		f[z]--; f[par[z]]--;
		f[u]++; f[v]++;
		g[z]-=2;
		g[u]++; g[v]++;
	}
	dfs2(1,0);
	
	int res = 0;
	for (int i = 1; i <= n; i++){
//		cout << i << " " << f[i] << " " << g[i] << " " << par[i] << "\n";
		(res += nCr(f[i],k))%=mod;
		(res -= nCr(g[i],k))%=mod;
	}
	(res += mod)%= mod;
	cout << res;
	
	return 0;
}
