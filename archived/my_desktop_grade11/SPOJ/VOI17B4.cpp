#include <bits/stdc++.h>
#define fix cout <<"fixed" << endl;

using namespace std;
long long int INF = 1e15;
int m, n, s, t, theta;
typedef pair<long long int, pair<int,int>> id;
vector <vector<id>> edge (100005);
vector <long long int> d;

void dijsktra(int x){
	priority_queue<id, vector<id>, greater<id>> pq;
	pq.push({0,{x,0}});
	
	while (!pq.empty()){
		int nodeU = pq.top().second.first;
		long long int distU = pq.top().first;
		int wayU = pq.top().second.second;
		pq.pop();
		
		if (distU != d[nodeU]) continue;
		for (auto& it: edge[nodeU]){
			int nodeV = it.second.first;
			long long int distUV = it.first;
			int wayV = it.second.second;
			if (wayU > 0) distUV += wayU*theta+wayV;
			
			//cout << nodeU + 1 << " " << distU << " " << wayU << " - " << nodeV + 1 << " " << distUV << " " << wayV << endl;
			if (distU+distUV<d[nodeV]){
				d[nodeV] = distU + distUV;
				pq.push({d[nodeV],{nodeV,wayV}});
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> s >> t >> theta;
	for (int i = 0; i < m; i++){
		int u, v;
		long long int tuv;
		cin >> u >> v >> tuv;
		edge[u-1].push_back({tuv,{v-1,i+1}});
		//edge[v-1].push_back({tuv,{u-1,i+1}});
	}
	
	d.assign(n,INF);
	d[s-1] = 0;
	dijsktra(s-1);
	//for (int i =0; i < n; i++) cout << d[i] << " "; cout << endl;	
	if (d[t-1]==INF) cout << -1; else cout << d[t-1];
	
	return 0;
}
