//greedy cut --> dp --> hint --> bin search

#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 5;
vector<int> edge[maxN];
int cmp, n, k, sz[maxN];
void dfs(int u, int p, int x){
	sz[u] = 1;
	for (int v: edge[u]) if (p!=v){
		dfs(v,u,x);
		sz[u] += sz[v];
	}
	if (sz[u]>=x) sz[u] = 0, cmp++;
}

bool check(int x){
	cmp = 0;
	dfs(1,-1,x);
	return cmp-1>=k;
}

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}	
	int l = 1, h = n, m, res = 1;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			res = m;
			l = m+1;
		} else h = m-1;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

