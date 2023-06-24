#include <bits/stdc++.h>

using namespace std;

//d[n][k] cho n so <= k bao nhieu cach tong = 10
long long int dp[51][69]; //d[n][k] so cach khi cho n so tong = 10
//a1 + a2 + ... + an = 10 = (a1 + a2 + ... + an-1) + an = 10
// cho an chay tu 0 -> K (1 cach) => (a1 + a2 + ... an-1) = 10 - an (DP cach) => moi gia tri an thi nhan duoc 1*DP cach
//DP[n][k] = sum(DP[n-1][10-i]) i:0->K

int n, k, m;
long long int D;

void initDP(){
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1; dp[0][10] = 0; 
	
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= 10; j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	
	for (int i = 0; i <= k; i++) dp[1][i] = 1; //dp[1][10] = 0;
// dp[0][10] = 0; dp[1][0] = 1;
//	cout << dp[0][10] << " wdawd"<<endl;
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= 10; j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	//KHAI BAO NGU DIT ME MAY dp[51][10] (dp[0][10] la dp[1][0])
	
	for (int i = 2; i <= n; i++) for (int j = 0; j <= 10; j++){
		//cout << i << " " << j << " " << dp[i][j] << endl;
		dp[i][j] = 0;
		for (int t = 0; t <= min(j,k); t++) //k la gioi han, j la tong phai <= ca 2
			dp[i][j] += dp[i-1][j-t]%D;
		//cout << i << " " << j << " " << dp[i][j] << endl;
	}
	
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//cin >> n >> k >> m;
	n = 15; k = 2; m = 2; D = 123;
	initDP();
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 10; j++) cout << dp[i][j] << " ";
		cout << endl;
	}
	long long int res = 0;
	for (int i = 0; i <= 10; i++) res += dp[i][10]*dp[10-i][10]*m;
	cout << res;
	return 0;
}
