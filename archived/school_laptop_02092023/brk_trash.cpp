#include<bits/stdc++.h>

using namespace std;
int dp[2005][15]; //[pos,inq]

int main(){
	cin >> n >> k >> s;
	s = "#" + s;
	if (s[1]=="?") dp[1][1] = 3;
	if (s[1]=="(") dp[1][1] 
	for (int i = 2; i <= n; i++){
		if (s[i]=="?") for (int inq = 0; inq <= k; inq++){
			if (inq<k) dp[i][inq] += dp[i-1][inq+1]; //dong ngoac
			if (inq>0) dp[i][inq] += dp[i-1][inq-1]; //mo ngoac
		}
		if (s[i]=="(") for (int inq = 1; inq <= k; inq++) dp[i][inq] = dp[i-1][inq-1];
		if (s[i]==")") for (int inq = 0; inq < k; inq++) dp[i][inq] = dp[i-1][inq+1];
	}
	cout << dp[n][0];
}
