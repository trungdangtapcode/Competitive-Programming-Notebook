#include <bits/stdc++.h>

using namespace std;
int n, m;
long long int a[305];
long long int dp[305][305][155];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	memset(dp,0,sizeof(dp));
	for (int i = n-1; i >= 0; i--){
		for (int j = i+1; j < n; j++){
			for (int k = 1; k <= m; k++){
				dp[i][j][k] = 0;
				if (j-i+1>=2&&k>=1){
					//cout << i << " " << j << endl;
					dp[i][j][k] = max({dp[i][j][k],dp[i+2][j][k-1]+abs(a[i]-a[i+1])
						,dp[i][j-2][k-1]+abs(a[j]-a[j-1])
						,dp[i+1][j-1][k-1]+abs(a[i]-a[j])});
				}
				dp[i][j][k] = max({dp[i][j][k],dp[i+1][j][k],dp[i][j-1][k]});
			}
		}
	}
	//long long int res = 0;
	//for (int i = 0; i <= m; i++) res = max(res,dp[0][n-1][i]);
	//cout << n << "-" << m  <<"-"<< a[0] <<"-" <<a[1] <<"-"<<a[2] << "-" <<a[3] <<"-"<<a[4] << "-" << a[5];
	cout << dp[0][n-1][m] << "-"<<dp[0][n-1][m];
	
	return 0;
}
