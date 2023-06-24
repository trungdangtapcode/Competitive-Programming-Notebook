#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;
typedef pair<int, long long int> id;
long long int INF = 1e15;
int n,m,s,t;
vector<vector<id>> edges (5005);
vector<long long int> d;
 
void dijkstra(int x) {
	priority_queue<id, vector<id>, greater<id>> pq;
	pq.push(id{ x,INF });
 
	while (!pq.empty()) {
		int nodeU = pq.top().first;
		long long int distU = pq.top().second;
		pq.pop();
 
		if (distU != d[nodeU]) continue;
		for (auto& i : edges[nodeU]) {
			int nodeV = i.first;
			long long int distUV = i.second;
			if (min(distU,distUV) > d[nodeV]) {
				d[nodeV] = min(distU,distUV);
				pq.push(id{ nodeV,d[nodeV] });
			}
		}
	}
	return;
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> s >> t;
 
	for (int i = 0; i < m; i++) {
		int a, b;
		long long int c;
		cin >> a >> b >> c;
		edges[a-1].push_back(id{ b-1,c });
		edges[b-1].push_back(id{ a-1,c });
	}
	d.assign(n, -INF); //doi thanh -INF vi dang tim cai lon nhat, lien thong cuc yeu (khoang cach = INF)
	d[s-1] = INF; //nho doi cai o trong dijkstra, max lien thong (khoang cach = 0)
	dijkstra(s-1);
	if (d[t-1]!=-INF)cout << d[t-1]; else cout << -1;
	return 0;
}
