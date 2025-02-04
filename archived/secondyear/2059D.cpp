#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int maxN = 1e3+5;
int n, s1, s2, m1, m2, d[maxN][maxN], final[maxN];
vector<int> edge1[maxN], edge2[maxN];
void solve(){
	cin >> n >> s1 >>s2;
	cin >> m1;
	set<ii> g1e;
	for (int i = 1; i <= n; i++) final[i] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) d[i][j] = 1e9;
	}
	for (int i = 1; i <= n; i++) edge1[i].clear(), edge2[i].clear();
	for (int i = 1; i <= m1; i++){
		int u, v;
		cin >> u >> v;
		if (u>v) swap(u,v);
		g1e.insert({u,v});
		edge1[u].push_back(v);
		edge1[v].push_back(u);
	}
	cin >> m2;
	for (int i = 1; i <= m2; i++){
		int u, v;
		cin >> u >> v;
		if (u>v) swap(u,v);
		if (g1e.count({u,v})) final[u] = final[v] = 1;
		edge2[u].push_back(v);
		edge2[v].push_back(u);
	}
	
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	d[s1][s2] = 0;
	pq.push({0,{s1,s2}});
	while (pq.size()){
		auto it = pq.top(); pq.pop();
		int u1 = it.second.first, u2 = it.second.second, du = it.first;
//		cout << u1 << " " << u2 << " " << du<< '\n';
		if (d[u1][u2]!=du) continue;
		if (u1==u2&&final[u1]){
			cout << du << "\n";
			return;
		}
		for (int v1: edge1[u1]) for (int v2: edge2[u2]){
			int c = abs(v1-v2);
			if (d[u1][u2]+c<d[v1][v2]){
				d[v1][v2] = d[u1][u2]+c;
				pq.push({d[v1][v2],{v1,v2}});
			}
		}
	}
	cout << -1 << "\n";
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

