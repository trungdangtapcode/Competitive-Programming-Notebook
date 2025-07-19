#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxN = 2e5+5;
int n, a, b, f[maxN][3];
vector<ii> edge[maxN];
void dfs(int u, int p = 0){
	f[u][0] = 0;
	f[u][1] = f[u][2] = 1e15;
	for (auto it: edge[u]){
		int v = it.first, w = it.second;
		if (v==p) continue;
		dfs(v,u);
		f[u][2] = min(f[u][2] + min({f[v][0],f[v][1],f[v][2]})+b,
			f[u][1] + min(f[v][0],f[v][1]) + w);
		f[u][1] = min(f[u][1] + min({f[v][0],f[v][1],f[v][2]})+b,
			f[u][0] + min(f[v][0],f[v][1]) + w);
		f[u][0] += min({f[v][0],f[v][1],f[v][2]})+b;
	}
//	cout << u << ": " <<f[u][0] << " " << f[u][1] << " " << f[u][2] << "\n";
}

void solve(){
	cin >> n >> a >> b;
	for  (int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		w = min(w*a,b);
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	dfs(1);
	cout << min({f[1][0],f[1][1],f[1][2]})+b << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

