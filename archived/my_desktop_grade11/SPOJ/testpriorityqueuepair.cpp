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
struct cumpare{
	bool operator()(id const& a, id const& b){
		return a.second > b.second;
	}
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
 	priority_queue<id, vector<id>, cumpare> pq;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push(id{a,b});
	}
	cout << pq.top().first <<" " << pq.top().second << endl;
 
	return 0;
}
