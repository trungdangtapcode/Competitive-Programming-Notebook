#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;

const int INF = 1e9;
typedef tuple<int, int, int> id;
int n, m;
vector<vector<id>> edge(3005);
vector<int> d, energy; 
vector<bool> isTram;

void dijsktra(int x){
	priority_queue<id,vector<id>,greater<id>> pq;
	pq.push(id{0,-1,x});
	
	while (!pq.empty()){
		int nodeU = get<2>(pq.top());
		int distU = get<0>(pq.top());
		pq.pop();
		
		if (distU != d[nodeU]) continue; ///
		for (auto& it: edge[nodeU]){
			int nodeV = get<2>(it);
			int distUV = get<0>(it);
						
			if (distU+distUV<d[nodeV]){
				d[nodeV] = distU + distUV;
				pq.push(id{d[nodeV],-1,nodeV});
			}
		}
	}
}

bool check(int w){
	vector<bool> inq;
	inq.assign(n,false);
	inq[0] = true;
	
	energy.assign(n,-1);
	energy[0] = w;
	queue<int> q; //not id cause rest 2 elements are in array (da dijsktra -> moi dinh da duoc co dinh) 
	q.push(0);
	
	while (!q.empty()){
		int nodeU = q.front();
		int distU = d[nodeU];
		int energyU = energy[nodeU];
		q.pop();
		inq[nodeU] = false;
		
		for (auto& it: edge[nodeU]){
			int nodeV = get<2>(it);
			int distUV = get<0>(it);
			int energyUV = get<1>(it);
			 
//			int energyV = energyU - energyUV;
//			if (energyV < 0) continue;
//			if (isTram[nodeV]) energyV = w;
			
			if (distU + distUV == d[nodeV]&&energy[nodeV]<energyU-energyUV){
				energy[nodeV] = energyU-energyUV;
				if (isTram[nodeV]) energy[nodeV] = w;
//				energy[nodeV] = energyV;
				if (!inq[nodeV]) q.push(nodeV), inq[nodeV] = true;
			}
		}
	}
	return (energy[n-1]!=-1);
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
	
	
	d.assign(n,INF);
	d[0] = 0;
	dijsktra(0);
	
	int low = 0, high = INF, mid, result;
	while (low<=high){
		mid = (low + high)/2;
		if (check(mid)){
			result = mid;
			high = mid - 1;
		} else low = mid + 1;
	}
	cout << result;
	//energy.assign(2*n,INF+1);
	//energy[0] = 0;
	
	//cout << tracing(n-1);
	//cout << energy[2];
	//cout << maxEnergy[n-1];
}
