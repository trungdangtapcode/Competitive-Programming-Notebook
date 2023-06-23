#include<bits/stdc++.h>

using namespace std;
int dp[100005], a[3], n;
int main(){
	cin >> n >> a[0] >> a[1] >> a[2];
	for (int i = 1; i <= n; i++) dp[i] = -1e9;
	for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) if (i>=a[j]) dp[i] = max(dp[i],dp[i-a[j]]+1);
	cout << dp[n];
	
	
	return 0;
}
