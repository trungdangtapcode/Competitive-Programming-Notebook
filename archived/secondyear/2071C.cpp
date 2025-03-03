#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
typedef pair<int,int> ii;
int n, s, t;
vector<int> edge[maxN];
vector<ii> res;
void dfs(int u, int p, int d){
	res.push_back({d,u});
	for (int v: edge[u]) if (v!=p){
		dfs(v,u, d+1);
	}
}
void solve(){
	cin >> n >> s >> t;
	res.clear();
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(t,-1,0);
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	for (ii it: res){
		cout << it.second << " ";
	}
	cout << "\n";
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

