#include <bits/stdc++.h>

using namespace std;

double dp[3005][3005]; //[i][j] i xu, j ngua
double p[3005];

int main(){
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) dp[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++){
			dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);
		}
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++) cout << fixed << setprecision(3) << dp[i][j] << " ";
//		cout << endl;
//	}
	cout << setprecision(10) <<dp[n][n/2+1];
	return 0;
}
