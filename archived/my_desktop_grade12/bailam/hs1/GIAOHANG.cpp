#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
int n, m, s, t;
vector<ii> edge[1005], d;
const int INF = 1e9;

void dijkstra(int x){
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({{0,0},x});
	
	while (!pq.empty()){
		int nodeU = pq.top().second;
		ii distU = pq.top().first;
		pq.pop();
		
		if (distU!=d[nodeU]) continue;
		for (auto it: edge[nodeU]){
			int nodeV = it.first;
			int distUV = it.second;
			
			if (d[nodeV].first>distU.first+distUV||(d[nodeV].first==distU.first+distUV&&d[nodeV].second>distU.second+1)){
				d[nodeV].first = distU.first + distUV;
				d[nodeV].second = distU.second + 1;
				pq.push({d[nodeV],nodeV});
			}
		}
	}
}

int main(){
	freopen("GIAOHANG.INP","r",stdin);
	freopen("GIAOHANG.OUT","w",stdout);
	
	cin >> n >> m >> s >> t;
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		edge[u].push_back({v,c});
		edge[v].push_back({u,c});
	}
	d.assign(n+1,{INF,INF});
	d[s].first = d[s].second = 0;
	dijkstra(s);
	if (d[t].first<INF) cout << d[t].first << " " << d[t].second;
	else cout << -1;
	
	return 0;
}
