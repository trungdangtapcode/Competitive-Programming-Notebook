#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

int n,m;
vector<vector<ii>> edge;
vector<int> d;
vector<long long int> cnt;
const int INF = 1e9;
void dijkstra(int x){
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0,x});
	while (!pq.empty()){
		int nodeU = pq.top().second;
		int distU = pq.top().first;
		pq.pop();
		if (distU!=d[nodeU]) continue;
		for (auto it: edge[nodeU]){
			int nodeV = it.first;
			int distUV = it.second;
			if (d[nodeV]>distU+distUV){
				d[nodeV] = distU+distUV;
				pq.push({d[nodeV],nodeV});
				cnt[nodeV] = cnt[nodeU];
			} 
			else if (d[nodeV]==distU+distUV) cnt[nodeV] += cnt[nodeU];
		}
	}
	return;
}

int main(){
	cin >> n >> m;
	edge.assign(n+5,vector<ii>());
	for (int i = 0, k, u, v, l; i < m; ++i){
		cin >> k >> u >> v >> l;
		edge[u].push_back({v,l});
		if (k==2) edge[v].push_back({u,l});
	}
	d.assign(n+5,INF);
	d[1] = 0;
	cnt.assign(n+5,0);
	cnt[1] = 1;
	dijkstra(1);
	cout << d[n] << " " << cnt[n];
	
	
	return 0;
}
