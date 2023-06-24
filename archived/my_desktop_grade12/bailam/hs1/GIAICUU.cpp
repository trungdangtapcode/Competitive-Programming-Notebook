#include <bits/stdc++.h>

using namespace std;
int n, m;
int c[105][105], d[105][105];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
const int INF = 1e9;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

void dijkstra(ii x){
	d[x.first][x.second] = c[x.first][x.second];
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({d[x.first][x.second],x});
	
	while (!pq.empty()){
		ii nodeU = pq.top().second;
		int distU = pq.top().first;
		pq.pop();
		
		if (d[nodeU.first][nodeU.second]!=distU) continue;
		for (int i = 0; i < 4; i++){
			ii nodeV;
			nodeV.first = nodeU.first+dx[i];
			nodeV.second = nodeU.second+dy[i];
			if (nodeV.first<1||nodeV.first>n||nodeV.second<1||nodeV.second>m) continue;
			int distUV = c[nodeV.first][nodeV.second];
			if (d[nodeV.first][nodeV.second]>distU+distUV){
				d[nodeV.first][nodeV.second]=distU+distUV;
				pq.push({d[nodeV.first][nodeV.second],nodeV});
			}
		}
	}
}

int main(){
	freopen("GIAICUU.INP","r",stdin);
	freopen("GIAICUU.OUT","w",stdout);
	
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			d[i][j] = INF;
		}
		int a, b, T;
		cin >> a >> b >> T;
		
		dijkstra({1,1});
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= m; j++) cout << d[i][j] << " ";
//			cout << '\n';
//		}
		if (d[a][b]<=T){
			cout << "YES\n" << T-d[a][b] << '\n';
		} else cout << "NO\n";
	}
	
	return 0;
}
