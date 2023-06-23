#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m;
vector<ii> edge[100005]; 
int big[100005], big_deg[100005];
bool removed[100005];

int low[100005], tin[100005], timer;
void dfs1(int u, int p){
	tin[u] = low[u] = ++timer;
	for (auto it: edge[u]){
		int v = it.first, pos = it.second;
		if (v==p) continue;
		if (tin[v]!=0){
			low[u] = min(low[u],tin[v]);
		} else {
			dfs1(v,u);
			low[u] = min(low[u],low[v]);
			if (low[v]>tin[u]) removed[pos] = true; 
		}
	}
}

void dfs2(int u, int x){
	big[u] = x;
	for (auto it: edge[u]){
		int v = it.first, pos = it.second;
		if (removed[pos]) continue;
		if (big[v]!=0) continue;
		dfs2(v,x);
	}
}


int main(){
	freopen("NETX.INP","r",stdin);
	freopen("NETX.OUT","w",stdout);
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back({v,i});
		edge[v].push_back({u,i});
	}
	dfs1(1,0);
	for (int i = 1, tplt = 0; i <= n; i++) if (big[i]==0) dfs2(i,++tplt);
	
	for (int u = 1; u <= n; u++){
		for (auto it: edge[u]){
			int v = it.first, pos = it.second;
//			if (removed[pos]) cout << u << " - " << v << endl;
			if (removed[pos]) big_deg[big[u]]++;
		}
	}
//	for (int i = 1; i <= n; i++) cout << big[i] << " ";
	
	
	int res = 0;
	for (int i = 1; i <= n; i++) if (big_deg[i]==1) res++;
	if (res%2) cout << res/2+1;
	else cout << res/2; 
	
	return 0;
}
