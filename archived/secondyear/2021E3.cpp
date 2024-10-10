#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int maxN = 4e5+5;
int n, m, p, f[maxN], g[maxN], s[maxN], id, dp[maxN];
vector<int> edge[maxN], res;

int cha[maxN];
int timcha(int x){
	return (x==cha[x]?x:cha[x]=timcha(cha[x]));
}

void dfs(int u){
	if (edge[u].empty()) return;
	int mv = -1;
	dp[u] = -1e15;
	for (int v: edge[u]){
		dfs(v);
		g[u] += g[v];
		int w = g[v]*(f[u]-f[v]);
		if (dp[v]+w>dp[u]) dp[u] = dp[v]+w, mv = v;
	}
//	cout << u << " = " << dp[u] << " " << g[u] << "\n";
	for (int v: edge[u]) if (v!=mv){
		int w = g[v]*(f[u]-f[v]);
		res.push_back(dp[v]+w);
	}
}

void solve(){
	cin >> n >> m >> p;
	for (int i = 1; i <= 2*n; i++) f[i] = g[i] = dp[i] = 0, cha[i] = i, edge[i].clear();
	int id = n;
	for (int i = 1; i <= p; i++){
		cin >> s[i];
		g[s[i]] = 1;
	}
	
	vector<iii> edgelist;
	for (int i = 1; i <= m; i++){
		int u, v, w; cin >> u >> v >> w;
		edgelist.push_back({w,{u,v}});
	}
	sort(edgelist.begin(),edgelist.end());
	for (auto it: edgelist){ //KRT
		int u = it.second.first, v = it.second.second,
			w = it.first;
		int x = timcha(u), y = timcha(v);
		if (x==y) continue;
		f[++id] = w;
		edge[id].push_back(x);
		edge[id].push_back(y);
		cha[x] = cha[y] = cha[id] = id;
	}
	dfs(id);
	res.push_back(dp[id]);
	sort(res.begin(),res.end());
//	for (int x: res){
//		cout << x << "\n";
//	}
	int cur = g[id]*f[id];
	for (int i = 1; i <= n ;i++){
		if (res.size()){
			cur -= res.back();
			res.pop_back();
		}
		cout << cur << " ";
	}
	cout << "\n";
//	exit(0);
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

