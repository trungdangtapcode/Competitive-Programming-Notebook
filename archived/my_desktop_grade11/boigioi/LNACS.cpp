#include <bits/stdc++.h>

using namespace std;

int n, m, dp[1005][1005], a[1005], b[1005];

int main(){
	
	ifstream fi("LNACS.INP");
	ofstream fo("LNACS.OUT");
	
	
	fi >> n >> m;
	for (int i = 1; i <= n; i++) fi >> a[i];
	for (int i = 1; i <= m; i++) fi >> b[i];
	
	memset(dp,0,sizeof(dp));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i]==b[j]) dp[i][j] = dp[max(i-2,0)][max(j-2,0)] + 1;
			else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
	}
	
	fo << dp[n][m];
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	fi.close();
	fo.close();
	
	return 0;
}
