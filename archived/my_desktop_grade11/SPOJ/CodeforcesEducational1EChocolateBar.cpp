#include <bits/stdc++.h>

using namespace std;
int n, m, k;
int dp[35][35][55];
const int INF = 1e7;

int getDP(int n, int m, int k){
//	cout << n << " " << m << " " << k << endl;
	if (n*m<k) return INF;//co the toi uu khoang lap for
	if (n*m==k||k==0) return 0; //k = 0 thoai mai
	if (dp[n][m][k]!=-1) return dp[n][m][k]; //ko cat
	int res = INF;
	for (int i = 1; i < n; i++){
		for (int j = 0; j <= k; j++){
			res = min(res,getDP(i,m,j)+getDP(n-i,m,k-j)+m*m);
		}
	}
	for (int i = 1; i < m; i++){
		for (int j = 0; j <= k; j++){
			res = min(res,getDP(n,i,j)+getDP(n,m-i,k-j)+n*n);
		}
	}
	dp[n][m][k] = res;
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	
	memset(dp,-1,sizeof(dp));
	
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		cout << getDP(n,m,k) << '\n';
	}
	
	return 0;
}
