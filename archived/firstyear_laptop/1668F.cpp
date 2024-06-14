#include<bits/stdc++.h>

using namespace std;
//lemma in tutorial
//par[u] = parity, root dont have parity
//condition (u,v) -> par[u] = par[v]
//remove order in node par[u] par[u]^1 par[u] ...  
//not only remove an edge we remove whole subtree (based on leaf)
//parity can be understanded to balance childs of v
// -> u-v edge is par[v] parity (following the minority)
const int maxN = 2e5+5;
int n, par[maxN];
vector<int> edge[maxN];
int check;
void dfs1(int u, int p){
	int c[2] = {0,0};
	for (int v: edge[u]) if (v!=p){
		dfs1(v,u);
		c[par[v]]++;
	}
	if (u!=1) c[par[u] = (c[0]>=c[1])]++;
	if ((c[0]+c[1])/2!=c[0]) check = 0;
}
void dfs2(int u, int p){
	vector<int> vec[2];
	for (int v: edge[u]) vec[par[v==p?u:v]].push_back(v);
	for (int id = edge[u].size()%2; vec[id].size(); id ^= 1){
		int v = vec[id].back(); vec[id].pop_back();
		if (v==p) cout << u << " " << v << "\n";
		else dfs2(v,u);
	}
}

void solve(){
	check = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	if (!check){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	dfs2(1,0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

