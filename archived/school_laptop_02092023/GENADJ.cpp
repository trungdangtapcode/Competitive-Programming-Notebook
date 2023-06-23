#include<bits/stdc++.h>

using namespace std;

string s;
int n, a[100005], dp[100005][5][5][5];
const int MOD = 1e9+7;
int main(){
	cin >> s;
//	s = "GTT"; //ATCG
	n = s.length();
	s = "#" + s;
	for (int i = 1; i <= n; i++){
		if (s[i]=='A') a[i] = 0;
		if (s[i]=='C') a[i] = 1;
		if (s[i]=='T') a[i] = 2;
		if (s[i]=='G') a[i] = 3;
		if (s[i]=='?') a[i] = 4;
	}
//	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++) dp[0][i][j][k] = 1;
	for (int i = 0; i < 4; i++){
		if (a[1]==4){
			for (int l = 0; l < 4; l++) dp[1][i][l][l] = 1;
			continue;
		}
		dp[1][i][a[1]][a[1]] = 1;
	}
	for (int p = 2; p <= n; p++) for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++){
		if (a[p]==4){
			for (int l = 0; l < 4; l++){
				if (k!=l) dp[p][i][j][l] += dp[p-1][i][j][k], dp[p][i][j][l] %= MOD;
				if (i==k) dp[p][j][l][l] += dp[p-1][i][j][k], dp[p][j][l][l] %= MOD;
			}
			continue;
		}
		if (k!=a[p]) dp[p][i][j][a[p]] += dp[p-1][i][j][k], dp[p][i][j][a[p]] %= MOD;
		if (i==k) dp[p][j][a[p]][a[p]] += dp[p-1][i][j][k], dp[p][j][a[p]][a[p]] %= MOD;
	}
	int res = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) res = (res+dp[n][i][j][i])%MOD;
	cout << res;
	
	return 0;
}
