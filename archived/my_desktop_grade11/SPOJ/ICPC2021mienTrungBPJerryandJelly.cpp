#include <bits/stdc++.h>

using namespace std;
int a, b, c, d, dp[105][105][105][15];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(dp,0,sizeof(dp));
	for (int u = 1; u <= 10; u++) for (int x = 1; x <= 100; x++) for (int y = 1; y <= 100; y++) for (int z = 1; z <= 100; z++){
		dp[x][y][z][u] = max({dp[x-1][y][z][u],dp[x][y-1][z][u],dp[x][y][z-1][u]});
		if (x>=u&&x<=y&&x<=z) dp[x][y][z][u] = max(dp[x][y][z][u],y*z);
		if (y>=u&&y<=z&&y<=x) dp[x][y][z][u] = max(dp[x][y][z][u],z*x);
		if (z>=u&&z<=x&&z<=y) dp[x][y][z][u] = max(dp[x][y][z][u],x*y);
		if (x>=u) dp[x][y][z][u] = max(dp[x][y][z][u],dp[x-u][y][z][u]+dp[u][y][z][u]); 
		if (y>=u) dp[x][y][z][u] = max(dp[x][y][z][u],dp[x][y-u][z][u]+dp[x][u][z][u]); 
		if (z>=u) dp[x][y][z][u] = max(dp[x][y][z][u],dp[x][y][z-u][u]+dp[x][y][u][u]); 	
	}
	int t; cin >> t;
	while (t--){
		cin >> a >> b >> c >> d;
		cout << dp[a][b][c][d] << '\n'; 	
	}
	
	return 0;
}
