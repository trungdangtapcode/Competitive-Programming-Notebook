	#include<iostream>
	#include<vector>
	#include<queue>
	#include<algorithm>
	#include<math.h>
	#include <tuple> 
	#define fix cout<<"fix"<<endl;
	using namespace std;
	typedef tuple<int, long long int, int> road;
	typedef tuple<int, long long int, long long int> id;
	long long int INF = 1e15;
	int n,m,s,t;
	vector<vector<road>> edges (50005);
	vector<long long int> d;
	 
	void dijkstra(int x) {
		priority_queue<id, vector<id>, greater<id>> pq;
		pq.push(id{ x,0,0 });
	 
		while (!pq.empty()) {
			int nodeU = get<0>(pq.top());
			long long int distU1 = get<1>(pq.top());
			long long int distU2 = get<2>(pq.top());
			pq.pop();
			
	 		//cout <<  nodeU << " " << distU1 << " " << distU2 << endl;
			if (distU1+distU2 != d[nodeU]) continue;
			for (auto& i : edges[nodeU]) {
				//fix;
				int nodeV = get<0>(i);
				long long int distUV = get<1>(i);
				long long int distV1, distV2;
				if (get<2>(i) == 1){
					distV1 = max(distU1,distUV);
					distV2 = distU2;
				} else {
					distV2 = max(distU2,distUV);
					distV1 = distU1;
				}
				
				if (distV1+distV2 < d[nodeV]) {
					d[nodeV] = distV1+distV2;
					pq.push(id{ nodeV, distV1,distV2});
				}
			}
		}
		return;
	}
	 
	int main() {
		ios::sync_with_stdio(0), cin.tie(0);
		cin >> n >> m >> s >> t;
	 
		for (int i = 0; i < m; i++) {
			int a, b, c;
			long long int d;
			cin >> a >> b >> c >> d;
			edges[b-1].push_back(make_tuple(c-1,d,a));
			edges[c-1].push_back(make_tuple(b-1,d,a));
		}
		d.assign(n, INF); 
		d[s-1] = 0; 
		dijkstra(s-1);
		if (d[t-1]!=INF)cout << d[t-1]; else cout << -1;
		return 0;
	}
