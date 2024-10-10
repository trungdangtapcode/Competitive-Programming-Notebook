#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e5+5;
int n, visied[maxN], d[maxN], par[maxN];
vector<int> edge[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i<= n; i++){
		d[i] = 0;
		edge[i].clear();
		visied[i] = 0;
	}
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		d[u]++;
		d[v]++;
	}
	
	auto isleaf = [&](int u){
		return u!=1&&d[u]==1;
	};
	queue<int> q, nq;
	q.push(1);
	visied[1] = 1;
	int res = n-1, cur = n-1;
	for (int depth = 1; depth <= n; ++depth){
		while (q.size()){
			int u = q.front(); q.pop();
			for (int v: edge[u]) if (!visied[v]){
				visied[v] = 1;
				nq.push(v);
				par[v] = u;
				cur--;
			}
			while (isleaf(u)){
				int p = par[u];
				d[p]--;
				cur++;
				u = p;
			}
		}
		q = nq;
		nq = queue<int>();
//		cout << depth << " " << cur << '\n';
		res = min(cur,res);
	}
	cout << res << "\n";
	
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

