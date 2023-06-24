#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii>::iterator iter;
typedef pair<ii,pair<iter,int>> pack;
vector<ii> edge[1005];
int d[1005];
priority_queue<pack, vector<pack>, greater<pack> > pq;
int t, n, m, nodeU, nodeV, distUV, distU, nodeBU;
iter it, itU;

int dijsktra(int s) {
	pq = priority_queue<pack, vector<pack>, greater<pack> > ();
	memset(d, 1, sizeof(d)); //0x3f (4.3MB)
	d[s] = 0;
	pq.push(pack(make_pair(0, s),make_pair(edge[0].end(),-1))); //nothing = edge[0] (it gia)
	while(!pq.empty()) {
		nodeU = pq.top().first.second; 
		distU = pq.top().first.first;
		itU = pq.top().second.first;
		nodeBU = pq.top().second.second;
		pq.pop();
		//if (nodeU == s && d[nodeU]) return d[s]; 
		if (nodeU == n+1) return d[n+1]; //node n+1 la node gia cua s
		//cout << s << ". " << nodeU << " " << distU << " " << nodeBU << endl;
		
		if (distU==d[nodeU]) 
		for (it = edge[nodeU].begin(); it != edge[nodeU].end(); it++) {
			nodeV = it->first; 
			if (nodeV == s) nodeV = n+1;
			distUV = it->second;
			if (d[nodeV] > d[nodeU] + distUV) {
				d[nodeV] = d[nodeU] + distUV;
				pq.push(pack(make_pair(d[nodeV], nodeV),make_pair(it,nodeU)));
				break;
			}
		}	
		if (nodeU!=s)
		for (itU++ ; itU != edge[nodeBU].end(); itU++) {
			nodeV = itU->first; 
			if (nodeV == s) nodeV = n+1;
			distUV = itU->second; //distBU-V
			if (d[nodeV] > d[nodeBU] + distUV) {
				d[nodeV] = d[nodeBU] + distUV;
				pq.push(pack(make_pair(d[nodeV], nodeV),make_pair(itU,nodeBU))); //cout << "pushed: " << nodeV << " from " << nodeBU <<" while " << nodeU << endl;
				break;
			}
		}
		//if (d[nodeU]==0) d[nodeU] = 1e9;
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
		for (int i = 1; i <= n; i++) sort(edge[i].begin(),edge[i].end(),[](ii a, ii b){return a.second<b.second;});
		for (int i = 1; i <= n; i++) cout << dijsktra(i) << endl; //doc VOI13B5TOURS13_2.cpp de hieu them (4.3MB)
	}
	return 0;
}
