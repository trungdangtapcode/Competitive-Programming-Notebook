#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+5;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int n, m, f[N][2];
vector<ii> edge[N];
void solve(){
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = 1e9+1;
	for (int i = 1; i <= m; i++){
		int u, v, t;
		cin >> u >> v >> t;
		edge[u].push_back({t, v});
		edge[v].push_back({t, u});
	}
	for (int i = 1; i <= n; i++){
		sort(edge[i].begin(), edge[i].end());
		reverse(edge[i].begin(), edge[i].end());
	}; 
	f[1][0] = 0;
	pq.push({0, {1,0}});
	while (pq.size()){
		auto it = pq.top(); pq.pop();
		int u = it.second.first, tu = it.first, ru = it.second.second;
//		while (edge[i].size()&&edge[i].back().first>=)
		if (tu>f[u][ru]) continue;
		for (auto it: edge[u]){
			int v = it.second, t = it.first;
			if (t<tu) continue;
			if (t==tu&&ru==1) continue;
//			if (v==4) cout << t << " " << tu << " " << u << "\n";
			if (t==tu){
				if (f[v][1]>t){
					f[v][1] = t;
					pq.push({t, {v, 1}});
				}
				continue;
			}
//			if (v==3) cout << t << " " << tu << " " << u << "\n"; 
			if (f[v][ru]>t){
				f[v][ru] = t;
//				if (v==4) cout << t << " " << tu << " " << u << "\n";
				pq.push({t, {v, ru}});
			};
		}
	}
	int res = min(f[n][0],f[n][1]);
	cout << (res>1e9?-1:res) << "\n";
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

