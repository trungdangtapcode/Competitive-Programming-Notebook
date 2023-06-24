#include<bits/stdc++.h>

using namespace std;
string s;
int n, dp[100005][2];
const int p = 1e9+7;
int main(){
	cin >> s;
	n = s.length();
	s = "#" + s;
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++){
		dp[i][1] = (dp[i-1][0] + dp[i-1][1])%p;
		if (s[i]=='n'&&s[i-1]=='n'||s[i]=='u'&&s[i-1]=='u') dp[i][0] = dp[i-1][1];
		if (s[i]=='m'||s[i]=='w') return cout << 0,0;
	}
	cout << (dp[n][0] + dp[n][1])%p;
	
	return 0;
}
