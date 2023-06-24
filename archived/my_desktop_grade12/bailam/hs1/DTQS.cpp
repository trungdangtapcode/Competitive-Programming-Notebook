#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m, s, t;
vector<int> d;
vector<ii> edge[100005];
const int INF = 1e9;

void dijkstra(int x){
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0,x});
	d[x] = 0;
	
	while (!pq.empty()){
		int nodeU = pq.top().second;
		int distU = pq.top().first;
		pq.pop();
		
		if (distU!=d[nodeU]) continue;
		for (auto it: edge[nodeU]){
			int nodeV = it.first;
			int distUV = it.second;
			if (d[nodeV]>distU+distUV){
				d[nodeV]=distU+distUV;
				pq.push({d[nodeV],nodeV});
			}
		}
	}
}

int main(){
	freopen("DTQS.INP","r",stdin);
	freopen("DTQS.OUT","w",stdout);
	
	cin >> n >> m >> s >> t;
	for (int i = 0, x, y, c; i < m; i++){
		cin >> x >> y >> c;
		edge[x].push_back({y,c});
		edge[y].push_back({x,c});
	}
	d.assign(n+5,INF);
	dijkstra(s);
	cout << (d[t]<INF?d[t]:-1);
	
	return 0;
}
