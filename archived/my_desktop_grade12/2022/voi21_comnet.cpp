#include<bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e18+7;

vector<int> edge[1005];
int sumEdge[1005], n, k, a, b;
int f[1005][5][1005];
void dfs(int p, int u){
	sumEdge[u] = 0;
	f[u][0][0] = f[u][1][0] = 1;
	for (int v: edge[u]) if (v!=p){
		dfs(u,v);
		sumEdge[u] += sumEdge[v] + 1;	
		for (int cntNode = k; cntNode >= 0; cntNode--) for (int cntEdge = sumEdge[u]; cntEdge >= 0; cntEdge--){
			for (int vNode = min(k,cntNode); vNode > 0; vNode--) for (int vEdge = min(cntEdge,sumEdge[v]); vEdge >= 0; vEdge--){
//				cout << u << " " << cntNode << " " << vNode << " " << cntEdge << " " << vEdge << endl;
				if (vNode==k) (f[u][cntNode][cntEdge] += 1ll*f[u][cntNode-vNode][cntEdge-vEdge]*f[v][vNode][vEdge]%mod) %= mod;	
				else if (cntEdge-vEdge-1>=0) (f[u][cntNode][cntEdge] += 1ll*f[u][cntNode-vNode][cntEdge-vEdge-1]*f[v][vNode][vEdge]%mod) %= mod;
			}
		}
	}
}

main(){
	cin >> n >> k >> a >> b;
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0,1);
	int res = 0;
	for (int i = a; i <= b; i++) (res += f[1][k][i])%=mod;
	cout << res;
	return 0;
}
