#include<bits/stdc++.h>

using namespace std;
int n, dp[4400005], a[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < (1<<22); i++) dp[i] = -1;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		dp[a[i]] = a[i];
	};
	for (int i = 0; i < 22; i++) for (int mask = 0; mask < (1<<22); mask++){
		if (mask&(1<<i)) dp[mask] = max(dp[mask],dp[mask^(1<<i)]);
	}
	for (int i = 0; i < n; i++) cout << dp[(a[i])^((1<<22)-1)] << " ";
	
	return 0;
}
