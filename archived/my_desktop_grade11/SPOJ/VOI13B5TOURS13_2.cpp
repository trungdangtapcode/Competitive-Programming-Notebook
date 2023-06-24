#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii>::iterator iter;
vector<ii> edge[1010];
int d[1010];
priority_queue<ii, vector<ii>, greater<ii> > pq;
int t, n, m, nodeU, nodeV, distUV, distU;
iter it;

int dijsktra(int s) {
	pq = priority_queue<ii, vector<ii>, greater<ii> > ();
	memset(d, 0x3f, sizeof(d)); 
	d[s] = 0;
	pq.push(ii(0, s));
	while(!pq.empty()) {
		nodeU = pq.top().second; 
		distU = pq.top().first;
		pq.pop();
		if (nodeU == s && d[nodeU]) return d[s]; 
		
		if (distU!=d[nodeU]) continue;
		for (it = edge[nodeU].begin(); it != edge[nodeU].end(); it++) {
			nodeV = it->first; 
			distUV = it->second;
			if (d[nodeV] > d[nodeU] + distUV) {
				d[nodeV] = d[nodeU] + distUV;
				pq.push(ii(d[nodeV], nodeV));
			}
		}
		if (d[nodeU]==0) d[nodeU] = 1e9;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) edge[i].clear();
		for (int i = 1; i <= m; i++) {
			cin >> nodeU >> nodeV >> distUV;
			edge[nodeU].push_back(ii(nodeV, distUV));
		}
		for (int i = 1; i <= n; i++) cout << dijsktra(i) << endl;
	}
	return 0;
}
