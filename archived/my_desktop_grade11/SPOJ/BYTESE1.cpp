#include <bits/stdc++.h>

using namespace std;

int vx[4] = {0,1,0,-1};
int vy[4] = {1,0,-1,0};
int d[105][105];
typedef pair<int,int> toado;
typedef pair<int,toado> id;
int n, m;
int c[105][105];

void dijkstra(toado s){
	priority_queue<id, vector<id>, greater<id>> pq;
	pq.push({c[1][1],s});
	
	while (!pq.empty()){
		int nodeUx = pq.top().second.first;
		int nodeUy = pq.top().second.second;
		int distU = pq.top().first;
		pq.pop(); 
		
		if (distU!=d[nodeUx][nodeUy]) continue;
		for (int i = 0; i < 4; i++){
			int nodeVx = nodeUx + vx[i];
			int nodeVy = nodeUy + vy[i];
			if (nodeVx<1||nodeVx>m||nodeVy<1||nodeVy>n) continue;
			int distUV = c[nodeVx][nodeVy];
			//cout << "(" << nodeUx << "," << nodeUy <<") -> (" << nodeVx <<","<<nodeVy<<")  " << distU <<" + " <<distUV <<endl;
			if (d[nodeVx][nodeVy] > distU + distUV){
				//cout << "added"<< endl;
				d[nodeVx][nodeVy] = distU + distUV;
				pq.push({d[nodeVx][nodeVy],{nodeVx,nodeVy}});
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int k; cin >> k;
	while (k--){
		memset(d,0,sizeof(d));
		cin >> m >> n;
		for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) cin >> c[i][j];
		
		memset(d,1,sizeof(d));
		d[1][1] = c[1][1];
		dijkstra({1,1});
//		for (int i = 1; i <= m; i++){
//			for (int j = 1; j <= n; j++) cout << d[i][j] << " ";
//			cout << endl;
//		}
		int a, b, t;
		cin >> a >> b >> t;
		cout << (d[a][b]<t?"YES":"NO") << '\n';
		if (d[a][b]<t) cout << t-d[a][b] << '\n';
	}
	
	return 0;
}
