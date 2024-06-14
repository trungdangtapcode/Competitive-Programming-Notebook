#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
typedef pair<int,int> ii;
int n, k, a[maxN], d[maxN], b[maxN];
vector<int> edge[maxN];
ii dfs(int u, int p){
	ii res = {b[u]?0:-1e9,u};
	for (int v: edge[u]) if (v!=p){
		auto it = dfs(v,u);
		res = max(res,{it.first+1,it.second});
	}
	return res;
}

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) b[i] = 0, edge[i].clear();
	for (int i = 1; i <= k; i++){
		cin >> a[i];
		b[a[i]] = 1;
	}
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if (k==1){
		cout << 0 << "\n";
		return;
	}
	auto it = dfs(a[1],0);
	int u = it.second;
	it = dfs(u,0);
	cout << (it.first+1)/2 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}
//https://pastebin.com/z3UCVELb
