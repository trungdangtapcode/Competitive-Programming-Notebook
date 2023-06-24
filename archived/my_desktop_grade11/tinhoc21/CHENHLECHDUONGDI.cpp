#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;
typedef pair<int, long long int> id;
long long int INF = 1e15;
int n,m,p;
vector<vector<id>> edges (50005);
vector<long long int> d;
vector<bool> biTat (10005);
 
void dijkstra(int x) {
	priority_queue<id, vector<id>, greater<id>> pq;
	pq.push(id{ x,0 });
 
	while (!pq.empty()) {
		int nodeU = pq.top().first;
		long long int distU = pq.top().second;
		pq.pop();
 
		if (distU != d[nodeU]||biTat[nodeU]) continue;
		for (auto& i : edges[nodeU]) {
			int nodeV = i.first;
			long long int distUV = i.second;
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
	cin >> n >> m >> p;
 
	for (int i = 0; i < m; i++) {
		int a, b;
		long long int c;
		cin >> a >> b >> c;
		edges[a-1].push_back(id{ b-1,c });
		edges[b-1].push_back(id{ a-1,c });
	}
	
	for (int i = 0; i < n; i++){
		biTat[i] = false;
	}
	d.assign(n, INF);
	d[0] = 0;
	dijkstra(0);
	long int S1 = d[n-1];
	
	for (int i = 0; i < p; i++){
		int a;
		cin >> a;
		biTat[a-1] = true;
	}
	d.assign(n, INF);
	d[0] = 0;
	dijkstra(0);
	long int S2 = d[n-1];
	
	if (S1==INF||S2==INF||biTat[n-1]) cout << -1; else cout << S2 <<" "<< S2-S1;
	return 0;
}
