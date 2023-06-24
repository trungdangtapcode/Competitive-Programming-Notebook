#include <bits/stdc++.h>

using namespace std;
long long p = 1e9 + 7;
int n,k;
int a[100005];
long long int dp[105][100005], sumLastDP[100005];

int main(){
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 1;
	for (int i = 0; i <= k; i++) sumLastDP[i] = 1;
	for (int i = 1; i <= n; i++){
		dp[i][0] = 1;
		for (int j = 1; j <= k; j++){ //sum: (j - x) | x: 0 -> a[i]  => sum(j-a[i],j)
			if (j > a[i]) dp[i][j] = (sumLastDP[j] - sumLastDP[j-a[i]-1] + p*p)%p; 
			else dp[i][j] = sumLastDP[j]%p; 
		}
		sumLastDP[0] = 1;
		for (int j = 1; j <= k; j++) sumLastDP[j] = (sumLastDP[j-1] + dp[i][j])%p; 
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 0; j <= k; j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	cout << dp[n][k];
	
	return 0;
}
