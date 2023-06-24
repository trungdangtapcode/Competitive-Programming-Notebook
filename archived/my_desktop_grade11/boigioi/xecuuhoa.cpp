#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;

const int INF = 1e9;
typedef tuple<int, int, int> id;
int n, m;
long long int w;
vector<vector<id>> edge(3005);
vector<int> d, e; 

void dijsktra(int x){
	priority_queue<id,vector<id>,greater<id>> pq;
	pq.push(id{0,0,x});
	
	while (!pq.empty()){
		int nodeU = get<2>(pq.top());
		int distU = get<0>(pq.top());
		int energyU = get<1>(pq.top());
		pq.pop();
		
		if (distU != d[nodeU]) continue; ///
		for (auto& it: edge[nodeU]){
			int nodeV = get<2>(it);
			int distUV = get<0>(it);
			int energyUV = get<1>(it);
			
			if (energyU+energyUV>w) continue;
						
			if (distU+distUV<d[nodeV]||(distU+distUV==d[nodeV]&&energyU+energyUV<e[nodeV])){
				d[nodeV] = distU + distUV;
				e[nodeV]=energyU+energyUV;
				pq.push(id{d[nodeV],e[nodeV],nodeV});
			}
		}
	}
}


int main(){
	cin >> n;
	cin >> m;
	cin >> w;
	for (int i = 0; i < m; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		edge[a-1].push_back(id{c,d,b-1});
		edge[b-1].push_back(id{c,d,a-1});
	}
	
	
	d.assign(n,INF);
	d[0] = 0;
	e.assign(n,INF);
	e[0] = 0;
	dijsktra(0);
	
	//cout << e[n-1]<< endl;
	cout << (d[n-1]<INF?d[n-1]:-1);
	//energy.assign(2*n,INF+1);
	//energy[0] = 0;
	
	//cout << tracing(n-1);
	//cout << energy[2];
	//cout << maxEnergy[n-1];
}

