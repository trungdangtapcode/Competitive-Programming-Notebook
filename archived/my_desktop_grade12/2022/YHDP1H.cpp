#include<bits/stdc++.h>

using namespace std;
int n, a[200005];
bool dp[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) dp[i] = false;
		dp[0] = true;
		for (int i = 1; i <= n; i++){
			if (i+a[i]<=n) dp[i+a[i]] |= dp[i-1];
			if (i-a[i]>=1) dp[i] |= dp[i-a[i]-1];
		}
		cout << (dp[n]?"YES\n":"NO\n");
	}
	
	return 0;
}
