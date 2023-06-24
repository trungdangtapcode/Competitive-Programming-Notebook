#include <bits/stdc++.h>

using namespace std;
unsigned int dp[3], new_dp[3];
const unsigned int p = 1e9+7;
int n;
int main(){
	cin >> n;
	dp[0] = dp[1] = dp[2] = 1;
	for (int i = 2; i <= n; i++){
		new_dp[0] = new_dp[2] = (dp[0]+dp[1]+dp[2])%p;
		new_dp[1] = (dp[0]+dp[2])%p;
		dp[0] = new_dp[0]; dp[1] = new_dp[1]; dp[2] = new_dp[2];
	}
	cout << (dp[0]+dp[1]+dp[2])%p;
	return 0;
}
