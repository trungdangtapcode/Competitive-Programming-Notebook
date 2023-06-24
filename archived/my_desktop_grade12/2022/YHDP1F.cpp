#include<bits/stdc++.h>

using namespace std;
int n,k;
vector<int> a, dp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		a.assign(k,0);
		dp.assign(n+2,0);
		for (int i = 0; i < k; i++) cin >> a[i];
		for (int i = 0; i <= n+1; i++) dp[i] = 2e9;
		for (int i = 0, t; i < k; i++){
			cin >> t;
			dp[a[i]] = t;
		};
		for (int i = 1; i <= n; i++) dp[i] = min(dp[i],dp[i-1]+1);
		for (int i = n; i >= 1; i--) dp[i] = min(dp[i],dp[i+1]+1);
		for (int i = 1; i <= n; i++) cout << dp[i] << " "; cout << "\n";
	}
	
	return 0;
}
