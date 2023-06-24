#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[100005], dp[100005];
main(){
	cin >> n;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		a[x]++;
	}
	dp[1] = a[1];
	for (int i = 2; i <= 1e5+1; i++) dp[i] = max(dp[i-1],dp[i-2]+a[i]*i);
	cout << dp[100001];
	
	return 0;
}
