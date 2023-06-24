#include <bits/stdc++.h>

using namespace std;
long int m, n;
long long int a[2*1010*1010];
long long int dp[2*1010*1010][2];

long int f(long int x, long int y){
	return (n+5)*x+y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dp,0,sizeof(dp));
	cin >> m >> n;
	for (long int i = 1; i <= m; i++) for (long int j = 1; j <= n; j++) cin >> a[f(i,j)];
//	
//	for (int i = 1; i < n; i++) dp[0][i][0] = a[0][i];
//	for (int i = 1; i < n; i++) dp[0][i][0] = max(dp[0][i-1][0],a[0][i]);
//	for (int i = n-2; i >= 0; i--) dp[0][i][1] = a[0][i];
//	for (int i = n-2; i >= 0; i--) dp[0][i][1] = max(dp[0][i+1][1]+a[0][i]);
//	
	for (long int i = 1; i <= m; i++){
		dp[f(i,1)][0] = max(dp[f(i-1,1)][0],dp[f(i-1,1)][1]) + a[f(i,1)];
		for (long int j = 2; j <= n; j++) dp[f(i,j)][0] = max(max(dp[f(i-1,j)][0],dp[f(i-1,j)][1]),dp[f(i,j-1)][0])+a[f(i,j)];
		dp[f(i,n)][1] = max(dp[f(i-1,n)][0],dp[f(i-1,n)][1]) + a[f(i,n)];
		for (long int j = n-1; j >= 1; j--) dp[f(i,j)][1] = max(max(dp[f(i-1,j)][0],dp[f(i-1,j)][1]),dp[f(i,j+1)][1])+a[f(i,j)];
	}
	long long int res = -1e18;
	for (long int i = 1; i <= n; i++) res = max(res,max(dp[f(m,i)][0],dp[f(m,i)][1]));
	cout << res << endl;
//	for (int i = 0; i <= m; i++){
//		for (int j = 1; j <= n; j++) cout <<dp[i][j][0] << " ";
//		cout << endl;
//	}
//	cout << " === " << endl;
//	for (int i = 0; i <= m; i++){
//		for (int j = 1; j <= n; j++) cout <<dp[i][j][1] << " ";
//		cout << endl;
//	}
	
	return 0;
}
