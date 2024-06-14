#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 5e5+5;
int n, a[maxN], f[maxN][5];
vector<int> edge[maxN];
void dfs(int u, int p){
	f[u][0] = a[u];
	f[u][1] = f[u][2] = f[u][3] = f[u][4] = -1e18;
	vector<int> vec;
	for (int v: edge[u]) if (v!=p){
		dfs(v,u);
		int tmp = max({f[v][1] - a[v], f[v][2],f[v][3],f[v][0]});
		int f1 = tmp, f2 = f[u][1]+tmp, 
		f3 = max(f[u][2]+tmp,f[u][3]+tmp);
//		vec.push_back(f[v][1]-a[v]);
//		f[u][0] = max(f[u][0],f0);
		f[u][1] = max(f[u][1],f1);
		f[u][2] = max(f[u][2],f2);
		f[u][3] = max(f[u][3],f3);
	}
	f[u][1] += a[u], f[u][2] += a[u], f[u][3] += a[u];
//	sort(vec.begin(),vec.end());
//	reverse(vec.begin(),vec.end());
//	if (vec.size()>=2) f[u][4] = vec[0] + vec[1];
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		edge[i].clear();
	}
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int res = 0;
	dfs(1,0);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 4; j++) res = max(res,f[i][j]-(j==2)*a[i]);
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
