#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, m, d[maxN], t0, t1, t2;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> edge[maxN];
void solve(){
	cin >> n >> m >> t0 >> t1 >> t2;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i <= m; i++){
		int u, v, l1, l2;
		cin >> u >> v >> l1 >> l2;
		edge[u].push_back({v,{l1,l2}});
		edge[v].push_back({u,{l1,l2}});
	}
	t1 = t0-t1;
	t2 = t0-t2;
	for (int i =1 ; i <= n; i++) d[i] = 1e9;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	d[n] = 0;
	pq.push({0,n});
	while (pq.size()){
		int du = pq.top().first, u = pq.top().second;
		pq.pop();
		if (du!=d[u]) continue;
//		cout << u << ": " << du << "\n";
		for (auto it: edge[u]){
			int v = it.first, l1 = it.second.first, l2 = it.second.second;
			//bus 
			if (!(du<t1&&du+l1>t2)){
				int dv = du+l1;
				if (dv<d[v]){
					d[v] = dv;
					pq.push({dv,v});
				}
			}
			//walk
			int dv = du+l2;
			dv = min(dv,max(t1,du)+l1);
//			cout << dv << "\n";
			if (dv<d[v]){
				d[v] = dv;
				pq.push({dv,v});
			}
		}
	}
	if (d[1]<=t0){
		cout << t0-d[1] << "\n"; 
	} else {
		cout << -1 << "\n";
	}
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

