#include <bits/stdc++.h>

using namespace std;
int n, deg[4005], m189 = 770; //770 = 1100000010
long long int a[2005];
int dp[2005][1050];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	
	memset(dp,-1,sizeof(dp));
	
	dp[0][0] = 0;
	dp[0][(1<<0)] = 1;
	for (int i = 1; i < n; i++){
		int d = a[i] - a[i-1];
		for (int bitmask = 0; bitmask < (1<<10);bitmask++) if (dp[i-1][bitmask] > -1) {
			int j = (d>=10?0:(bitmask<<d)%1024);
			if (!(j&m189)) dp[i][j] = max(dp[i][j],dp[i-1][bitmask]+1); else dp[i][j] = max(dp[i][j],dp[i-1][bitmask]);
		}
	}
	int res = 0;
	for (int j = 0; j < (1<<10); j++) res = max(res,dp[n-1][j]);
	cout << n-res;
	
	
	return 0;
}
