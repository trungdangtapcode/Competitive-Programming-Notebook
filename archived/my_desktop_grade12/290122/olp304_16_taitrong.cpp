#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int d[1005], n, m, s, t;
vector<ii> edge[1005];
void dijkstra(){
	for (int i = 1; i <= n; i++) d[i] = -1e9;
	d[s] = 1e9;
	priority_queue<ii> pq;
	pq.push({1e9,s});
	while (pq.size()){
		int u = pq.top().second, du = pq.top().first; pq.pop();
		if (d[u]!=du) continue;
		for (auto it: edge[u]){
			int v = it.first, c = it.second;
			if (d[v]<min(du,c)) pq.push({d[v]=min(du,c), v});
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("TAITRONG.INP","r",stdin);
	freopen("TAITRONG.OUT","w",stdout);
	cin >> n >> m >> s >> t;
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		edge[u].push_back({v,c});
		edge[v].push_back({u,c});
	}
	dijkstra();
	cout << d[t];
	return 0;
}
