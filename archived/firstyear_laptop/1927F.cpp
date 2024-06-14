#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, cha[maxN], u[maxN], v[maxN], m;
typedef pair<int,int> ii;
vector<ii> edgelist;

int timcha(int x){
	return (x==cha[x]?x:cha[x]=timcha(cha[x]));
}
bool hop(int u, int v){
	u = timcha(u), v = timcha(v);
	if (u==v) return 0;
	cha[u] = v;
	return 1;
}
bool visited[maxN];
vector<int> edge[maxN];
vector<int> path;
bool dfs(int u, int s, int t){
	visited[u] = 1;
	if (u==t) return 1;
	for (int v: edge[u]){
		if (visited[v]||v==t&&u==s) continue;
		if (!dfs(v,s,t)) continue;
		path.push_back(v);
		return 1;
	}
	return 0;
}

void solve(){
	cin >> n >> m;
	edgelist.clear();
	for (int i = 1; i <= n; i++) cha[i]= i, visited[i] = 0, edge[i].clear();
	for (int i = 1; i <= m; i++){
		int w;
		cin >> u[i] >> v[i] >> w;
		edgelist.push_back({w,i});
		edge[u[i]].push_back(v[i]);
		edge[v[i]].push_back(u[i]);
	}
	sort(edgelist.begin(),edgelist.end());
	reverse(edgelist.begin(),edgelist.end());
	int res = 1e9, trace = -1;
	for (auto it: edgelist){
		int i = it.second;
		if (!hop(u[i],v[i])){
			res = it.first;
			trace = i;
		}
	}
	path.clear();
	path.push_back(u[trace]);
	dfs(u[trace],u[trace],v[trace]);
	cout << res << " " << path.size() << "\n";
	for (int x: path) cout << x << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
