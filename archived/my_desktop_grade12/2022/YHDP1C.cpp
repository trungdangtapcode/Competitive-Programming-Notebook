#include<bits/stdc++.h>

using namespace std;
string s;
int n, prv[200005][26], dp[200005][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> s;
		n = s.length();
		s = "#" + s;
		for (int i = 1; i <= n; i++) for (int j = 0; j < 26; j++){
			prv[i][j] = (j==s[i]-'a'?i:prv[i-1][j]);
		}	
		int res = 0;
		for (int i = 1, mmax = 0; i <= n; i++){
			dp[i][1] = res + 1;
			dp[i][0] = 0;
			if (prv[i-1][s[i]-'a']!=0) dp[i][0] = dp[prv[i-1][s[i]-'a']][1] + 1;
			res = max(res,dp[i][0]);
		}
		cout << n-res << "\n";
	}
	return 0;
}
