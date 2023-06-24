#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
int n, res;
vector<int> edge[200005];
int dfs(int p, int u){
	int ans = 1;
	for (int v: edge[u]) if (v!=p){
		ans = max(ans,dfs(u,v)+1);
	}
	(res += ans)%=mod;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		res = 0;
		for (int i = 1; i <= n; i++) edge[i].clear();
		for (int i = 1, u, v; i < n; i++){
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(0,1);
		for (int i = 1; i < n; i++) (res *= 2)%= mod;
		cout << res << "\n";
	}
	
	
	return 0;
}
