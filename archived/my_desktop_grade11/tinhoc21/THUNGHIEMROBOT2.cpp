#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> toado;
typedef pair<int, toado> id;
bool a[305][305];
int d[305][305];
int m, n, x, y;
int INF = 1e6;
int Vx[4] = {-1,0,1,0}; //x, y theo [] (not Oxy) nen x la chieu doc (hang)
int Vy[4] = {0,1,0,-1};

void dijsktra(toado x){
	priority_queue<id,vector<id>,greater<id>> pq;
	pq.push({1,x});
	
	while (!pq.empty()){
		toado nodeU = pq.top().second;
		int distU = pq.top().first;
		pq.pop();
		
		if (distU!=d[nodeU.first][nodeU.second]||a[nodeU.first][nodeU.second]) continue;
		if (nodeU.first<1||nodeU.first>m||nodeU.second<1||nodeU.second>n) continue;
		for (int i = 0; i < 4; i++){
			toado nodeV = {nodeU.first+Vx[i],nodeU.second+Vy[i]};
			int distUV = 1;
			
			if (distU + distUV < d[nodeV.first][nodeV.second]){
				d[nodeV.first][nodeV.second] = distU + distUV;
				pq.push({d[nodeV.first][nodeV.second],nodeV});
			}
		}
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(d,1,sizeof(d));
	//for (int i = 0; i <= m+1; i++) for (int j = 0; j <= n+1; j++) d[i][j] = INF;
	cin >> m >> n >> x >> y;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++){
		cin >> a[i][j];
	}	
	
	//x--; y--;
	d[x][y] = 1;
	dijsktra({x,y});
	//cout << d[2][3] << " - " << endl;
//	int result = INF;
//	cout << result;
	//cout << dp(5,1);
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) cout << dp(i,j) << " ";
//		cout << endl;
//	}
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= n; j++) cout << d[i][j] << " ";
//		cout << endl;
//	}
	int result = INF;
	for (int i = 1; i <= m; i++) result = min(result,min(d[i][1],d[i][n]));
	for (int i = 1; i <= n; i++) result = min(result,min(d[1][i],d[m][i]));
	cout << result;
	
	return 0;
}
