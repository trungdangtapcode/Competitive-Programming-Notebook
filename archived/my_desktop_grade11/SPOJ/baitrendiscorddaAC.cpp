#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;
typedef pair<int, double> id;
const int INF = 1e9;
int n,w;
double m;
double cost[1005][1005];
int x[1005], y[1005];
vector<vector<id>> edges (1000);
vector<double> d;
bool connected[1005][1005];
 
void dijkstra(int x) {
	priority_queue<id, vector<id>, greater<id>> pq;
	pq.push(id{ x,0 });
 
	while (!pq.empty()) {
		int nodeU = pq.top().first;
		double distU = pq.top().second;
		pq.pop();
 
		if (distU != d[nodeU]) continue;
		for (auto& i : edges[nodeU]) {
			int nodeV = i.first;
			double distUV = i.second;
			if (distU + distUV < d[nodeV]) {
				d[nodeV] = distU + distUV;
				pq.push(id{ nodeV,d[nodeV] });
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
		for (int j = 0; j < n; j++)
			cost[i][j] = INF;
 
	for (int i = 0; i < w; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		connected[p1-1][p2-1] = true;
		connected[p2-1][p1-1] = true;
	}
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cost[i][j] != INF) continue;
 
			if (connected[i][j]) {
				cost[i][j] = 0;
				cost[j][i] = cost[i][j];
			}
			else {
				cost[i][j] = sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));
				cost[j][i] = cost[i][j];
			}
 
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
		cout << int(d[n-1]*1000);
	else
		cout << -1;
	return 0;
}
