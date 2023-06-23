#include<bits/stdc++.h>
using namespace std;
int n, q, cnt[170005], l[170005];
vector<int> edge[170005];

void dfs(int u, int level){
	l[u] = level;
	for (int v: edge[u]){
		if (l[v]==-1) dfs(v,level+1);
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> q;
		for (int i = 1; i <= n; i++) edge[i].clear(), l[i] = -1, cnt[i] = 0;
		for (int i = 1, u, v; i < n; i++){
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for (int i = 0, a; i < q; i++) cin >> a;
		dfs(1,1);
		for (int i = 1; i <= n; i++){
			cnt[l[i]]++;
		}
		int res = 0;
		for (int i = 1; i <= n; i++){
			if (q<cnt[i]) break;
			q -= cnt[i];
			res += cnt[i];
		}
		cout << res << "\n";
	}
	return 0;
}
