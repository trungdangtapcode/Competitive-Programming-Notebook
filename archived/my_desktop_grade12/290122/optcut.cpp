#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
ii dp[2005][2005];
int a[2005], n;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) a[i] += a[i-1];
	for (int i = 1; i <= n; i++) dp[i][i] = {0,i};
	for (int i = 1; i <= n; i++){
		for (int j = i-1; j > 0; j--){
			dp[j][i].first = 1e9;
			for (int k = dp[j][i-1].second; k <= dp[j+1][i].second; k++)
				dp[j][i] = min(dp[j][i],{dp[j][k].first+dp[k+1][i].first+a[i]-a[j-1],k});
		}
	}
	cout << dp[1][n].first;
	
	return 0;
}
