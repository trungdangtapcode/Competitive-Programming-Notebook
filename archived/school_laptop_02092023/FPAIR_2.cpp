#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
int p[100005], n, m, k;
ii d[34][100005];
vector<ii> edge[100005];
bool check_group[36][100005];

void dijkstra(int idx){
	for (int i = 1; i <= n; i++) d[idx][i] = {1e9,1e9}; 
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	for (int i = 0; i < k; i++){
		if (check_group[idx][i]) 
		d[idx][p[i]] = min(d[idx][p[i]],{0,i}), pq.push({{0,i},p[i]});
	}
	while (!pq.empty()){
		int u = pq.top().second;
		ii du = pq.top().first;
		pq.pop();
		if (du!=d[idx][u]) continue;
		for (auto it: edge[u]){
			int v = it.first, c = it.second;
			if (make_pair(du.first+c,du.second)<d[idx][v]){
				d[idx][v] = make_pair(du.first+c,du.second);
				pq.push(make_pair(d[idx][v],v));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++){
		cin >> p[i];
	}
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		edge[u].push_back({v,c});
		edge[v].push_back({u,c});
	}
	for (int i = 0; i < k; i++){
		for (int j = 0; j < 17; j++){
			if (i&(1<<j)) check_group[j][i] = true;
			else check_group[j+17][i] = true;
		}
	}
//	for (int i = 0; i < 40; i++){
//		for (int j = 0; j < k; j++) cout << check_group[i][j];
//		cout << endl;
//	}
	for (int i = 0; i < 17*2; i++){
//		cout << "group: ";
//		for (int j = 0; j < k; j++) if (check_group[i][j]) cout << p[j] << " "; cout << endl;
		dijkstra(i);
//		for (int j = 1; j <= n; j++) cout << d[i][j].first << " "; cout << endl;
	}
	for (int i = 0; i < k; i++){
		ii mmin = {1e9,1e9};
		for (int j = 0; j < 17*2; j++) if (!check_group[j][i]) mmin = min(mmin,d[j][p[i]]);
		cout << mmin.second+1 << " "; 
	}
	
	return 0;
}
