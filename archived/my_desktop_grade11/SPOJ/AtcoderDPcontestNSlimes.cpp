#include <bits/stdc++.h>

using namespace std;
int n;
long long int a[405], dp[405][405];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], dp[i][i] = 0, a[i] += a[i-1];
	
	for (int l = 2; l <= n; l++) for (int i = 1, j = l; j <= n; i++, j++){
		dp[i][j] = 1e16;
		for (int k = i; k <= j-1; k++){
			dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
		dp[i][j] += a[j] - a[i-1];
	}
	cout << dp[1][n];
	
	return 0;
}
