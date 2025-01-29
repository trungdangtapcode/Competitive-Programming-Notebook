#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, res;
vector<int> edge[maxN];
int dfs(int u, int p){
	int f = edge[u].size(), g = 0;
	int fi = 0, se = 0;
	for (int v: edge[u]) if (v!=p){
		int x = dfs(v,u);
		int y = max((int)edge[v].size(),x);
		f = max(f, y);
		g = max(g, y);
		
		if (x!=0) res = max(res,x+(int)edge[u].size()-1);	
		res = max(res,(int)edge[u].size()+(int)edge[v].size()-2);
		if (fi<y){
			se = fi;
			fi = y;
		} else {
			if (se<y) se = y;
		}
	}
	if (se!=0) res = max(res, fi+se-1);
	return g;
}

void solve(){
	cin >> n;
	res = 0;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	cout << res << "\n";
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

