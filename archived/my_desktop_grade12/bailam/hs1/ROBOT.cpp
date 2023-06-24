#include<bits/stdc++.h>

using namespace std;
long long int dp[1005][1005];
int n, m;
int main(){
	freopen("ROBOT.INP","r",stdin);
	freopen("ROBOT.OUT","w",stdout);
	
	memset(dp,1,sizeof(dp));
	cin >> n >> m;
	for (int i = 1, a; i <= n; i++) for (int j = 1; j <= m; j++){
		cin >> a;
		if (i==1&&j==1){
			dp[i][j] = a;
			continue;
		}
		dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+a;
	}
	cin >> n >> m;
	cout << dp[n][m];
	
	return 0;
}
