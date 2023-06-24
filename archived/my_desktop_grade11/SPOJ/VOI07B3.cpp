#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;

const int INF = 1e9;
typedef tuple<int, int, int> id;
int n, m;
vector<vector<id>> edge(3005);
vector<int> d, energy, trace, maxEnergy; //deleted: energy means max of energy not energy u -> v (it is in id)
vector<bool> isTram;

void dijsktra(int x){
	priority_queue<id,vector<id>,greater<id>> pq;
	pq.push(id{0,0,x});
	
	while (!pq.empty()){
		int nodeU = get<2>(pq.top());
		int distU = get<0>(pq.top());
		int energyU = get<1>(pq.top());
		//int maxEnergyU = get<3>(pq.top());
		pq.pop();
		
		if (distU != d[nodeU]) continue; ///
		for (auto& it: edge[nodeU]){
			int nodeV = get<2>(it);
			int distUV = get<0>(it);
			int energyUV = get<1>(it);
			
			//
			int energyV;
			//if (isTram[nodeU]) energyV = max(energyU,energyUV); else energyV = energyU + energyUV;
			if (isTram[nodeU]) energyV = energyUV; else energyV = energyU + energyUV;
			int maxEnergyV = energyV;
			//if (isTram[nodeU]) maxEnergyV = max(energyU,energyUV); else maxEnergyV = energyU + energyUV;
			maxEnergyV = max(maxEnergyV,maxEnergy[nodeU]); //
						
			if (distU+distUV<d[nodeV]||(distU+distUV==d[nodeV]&& (maxEnergyV<maxEnergy[nodeV]||(maxEnergyV==maxEnergy[nodeV]&&energyV<energy[nodeV])) )){
				d[nodeV] = distU + distUV;
				energy[nodeV] = energyV;
				maxEnergy[nodeV] = maxEnergyV;
				//trace[nodeV] = nodeU;
				pq.push(id{d[nodeV],energy[nodeV],nodeV});
			}
		}
	}
}

int tracing(int x){
	if (trace[x]==-1) return 0;
	else return max(tracing(trace[x]),energy[x]);
}

int main(){
	cin >> n;
	isTram.assign(n,false);
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		isTram[i] = x;
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		edge[a-1].push_back(id{c,d,b-1});
		edge[b-1].push_back(id{c,d,a-1});
	}
	
	energy.assign(n,INF);
	energy[0] = 0;
	maxEnergy.assign(n,INF);
	maxEnergy[0] = 0;
	//trace.assign(n,-1);
	d.assign(n,INF);
	d[0] = 0;
	dijsktra(0);
	
	//cout << tracing(n-1);
	
	cout << maxEnergy[n-1];
}
