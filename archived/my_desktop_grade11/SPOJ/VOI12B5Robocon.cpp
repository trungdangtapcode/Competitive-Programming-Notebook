#include <bits/stdc++.h>
int n, k;
int INF = 1e6;
int dp[505][505][2];

using namespace std;int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(dp,-1,sizeof(dp));
	
	cin >> n >> k;
	for (int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		dp[a][b][0] = INF;
		dp[a][b][1] = INF;
	}
	
	dp[1][1][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) if (dp[i][j][0]==-1){
			dp[i][j][0]= INF;
			if (i>1) dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][0]);
			if (j>1) dp[i][j][0] = min(dp[i][j][0],dp[i][j-1][0]);
			if (i>1&&j>1) dp[i][j][0] = min(dp[i][j][0],dp[i-1][j-1][0]);
			dp[i][j][0]++;
		}
	}
	dp[1][n][1] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = n; j >= 1; j--) if (dp[i][j][1]==-1){
			dp[i][j][1]= INF;
			if (i>1) dp[i][j][1] = min(dp[i][j][1],dp[i-1][j][1]);
			if (j<n) dp[i][j][1] = min(dp[i][j][1],dp[i][j+1][1]);
			if (i>1&&j<n) dp[i][j][1] = min(dp[i][j][1],dp[i-1][j+1][1]);
			dp[i][j][1]++;
		}
	}
	
	int res = INF;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) if (dp[i][j][0]==dp[i][j][1]) res = min(res,max(dp[i][j][0],dp[i][j][1]));
	}
	cout << res << endl;
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++) cout << dp[i][j][1] << " ";
//		cout << endl;
//	}
	
	return 0;
}
