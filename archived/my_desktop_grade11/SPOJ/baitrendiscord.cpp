#include <bits/stdc++.h>
using namespace std;
typedef pair<int, double> id;
//const int INF = 1e5;
const double INF = double(1e15+5.0);
int n,w;
double m;
double cost[1005][1005];
int x[1005], y[1005];
vector<vector<id>> edges (1000);
vector<double> d;
bool connected[1005][1005];
 
void dijkstra(int x) {
	priority_queue<id, vector<id>, greater<id>> pq;
	pq.push(id{x,0});
 
	while (!pq.empty()) {
		int nodeU = pq.top().first;
		double distU = pq.top().second;
		pq.pop();
 
		if (distU > d[nodeU]) continue;
		for (auto i : edges[nodeU]) {
			int nodeV = i.first;
			double distUV = i.second;
			if (distU + distUV < d[nodeV]) {
				d[nodeV] = distU + distUV;
				pq.push(id{nodeV,d[nodeV]});
			}
		}
	}
	return;
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> w;
	cin >> m;
 
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cost[i][j] = INF;
			connected[i][j] = false;
		}
 
	for (int i = 0; i < w; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		p1--;
		p2--;
		edges[p1].push_back(id{ p2,0});
		edges[p2].push_back(id{ p1,0 });
		cost[p1][p2] = 0;
		cost[p2][p1] = 0;
		//connected[p1-1][p2-1] = true;
		//connected[p2-1][p1-1] = true;
	}
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j){
			if ((cost[i][j] != INF)||(cost[j][i] != INF)) continue;
 
			cost[i][j] = sqrt((x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]));
			cost[j][i] = cost[i][j];
 
			if (cost[i][j] <= m) {
				edges[i].push_back(id{ j,cost[i][j] });
				edges[j].push_back(id{ i,cost[i][j] });
			}
		}
	}
 
	d.assign(n, INF);
	d[0] = 0;
	dijkstra(0);
 
	if (d[n - 1] != INF)
		cout << (long long int)(d[n-1]*1000ll);
	else
		cout << -1;
	return 0;
}
