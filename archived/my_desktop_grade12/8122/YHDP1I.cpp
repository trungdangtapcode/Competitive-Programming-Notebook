#include<bits/stdc++.h>

using namespace std;

int n, m, k, dp[35][35][55];
int f(int n, int m, int k){
	if (k==0||k==m*n) return 0;
	if (k<0||k>m*n) return 1e9;
	if (dp[n][m][k]!=-1) return dp[n][m][k];
	int &res = dp[n][m][k] = 1e9;
	for (int i = 1; i < n; i++) for (int kk = 0; kk <= k; kk++) res = min(res,m*m+f(i,m,kk)+f(n-i,m,k-kk));
	for (int i = 1; i < m; i++) for (int kk = 0; kk <= k; kk++) res = min(res,n*n+f(n,i,kk)+f(n,m-i,k-kk));
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 30; i++) for (int j = 1; j <= 30; j++) for (int k = 0; k <= 50; k++) dp[i][j][k] = -1;
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		cout << f(n,m,k) << "\n";
	}
	
	return 0;
}
