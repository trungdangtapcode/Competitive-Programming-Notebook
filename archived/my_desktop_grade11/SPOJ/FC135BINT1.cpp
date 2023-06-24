#include <bits/stdc++.h>

using namespace std;
int dp[10005]; //so cay tknp co i phan tu
const int p = 1e9+7;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	memset(dp,0,sizeof(dp));
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= 1e4; i++){
		for (int j = 0; j <= i-1; j++){
			dp[i] = (dp[i]+1ll*dp[j]*dp[i-j-1])%p;
		}
	}
	int t, x; cin >> t;
	while (t--){
		cin >> x;
		cout << dp[x] << '\n';
	}
	return 0;
}
