#include <bits/stdc++.h>

using namespace std;
bool a[305][305];
int d[305][305];
int m, n, x, y;
int INF = 1e6;

int dp(int i, int j){
	//cout << x <<' ' << y << endl;
	if (i<0||j<0||a[i][j]) return INF;
	//if (i==x&&j==y) return 0;
	if (d[i][j]!=-1) return d[i][j];
	d[i][j] = min(dp(i-1,j)+1,dp(i,j-1)+1);
	return d[i][j];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(d,-1,sizeof(d));
	cin >> m >> n >> x >> y;
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++){
		cin >> a[i][j];
	}	
	
	x--; y--;
	d[x][y] = 0;
	//cout << d[2][3] << " - " << endl;
	int result = INF;
	for (int i = 0; i < n; i++){
		result = min(result,dp(m-1,i)); 
	}
	for (int i = 0; i < m; i++){
		result = min(result,dp(i,n-1)); 
	}
	cout << result;
	//cout << dp(5,1);
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) cout << dp(i,j) << " ";
//		cout << endl;
//	}
	
	return 0;
}
