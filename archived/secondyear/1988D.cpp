#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 3e5+5;
typedef vector<int> vi;
vi edge[maxN];
int n, a[maxN], deg[maxN], f[maxN][22], pf[maxN][22], sf[maxN][22], tmp[22];
void dfs(int u, int p){
	for (int v: edge[u]) if (v!=p){
		dfs(v,u);
	}
	for (int i = 1; i <= 20; i++){
		f[u][i] = a[u]*i;
		for (int v: edge[u]) if (v!=p){
			f[u][i]  += min(pf[v][i-1],sf[v][i+1]);
		}
	}
	pf[u][0] = sf[u][21] = 1e18;
	for (int i = 1; i <= 20; i++) pf[u][i] = min(pf[u][i-1],f[u][i]);
	for (int i = 20; i >= 1; i--) sf[u][i] = min(sf[u][i+1],f[u][i]);
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i= 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	dfs(1,0);
	cout << sf[1][1] << "\n";
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

