#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
int n, m, k, p[100005];
vector<ii> d, edge[100005];
vector<int> s, t;
void dijkstra(){
	d.assign(n+1,{2e9,-1});	
	priority_queue<iii,vector<iii>,greater<iii>> pq;
	for (int x: s){
		d[p[x]] = min(d[p[x]],{0,x});
		pq.push({d[p[x]],p[x]});
	}
	while (!pq.empty()){
		int u = pq.top().second;
		ii du = pq.top().first; pq.pop();
		if (du!=d[u]) continue;
		for (auto it: edge[u]){
			int v = it.first, c = it.second;
			if (d[v]>ii{du.first+c,du.second})
				pq.push({d[v] = {du.first+c,du.second},v});
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) cin >> p[i];
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		edge[u].push_back({v,c});
		edge[v].push_back({u,c});
	}
	vector<ii> res(k,{2e9,-1});
	for (int i = 0; i < 17; i++){
		s.clear(); t.clear();
		for (int j = 0; j < k; j++) if (j&(1<<i)) s.push_back(j); else t.push_back(j);
		for (int j = 0; j < 2; j++){
			dijkstra();
			for (int x: t) res[x] = min(res[x],d[p[x]]);
			swap(s,t);		
		}
	}
	for (int i = 0; i < k; i++) cout << res[i].second+1 << " ";
//	dijkstra({1,0,2});
//	for (int i = 1; i <= n; i++) cout << d[i].first << " ";
	
	return 0;
}
