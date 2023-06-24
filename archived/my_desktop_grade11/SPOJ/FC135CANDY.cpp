#include <bits/stdc++.h>

using namespace std;
string s, t;
int n, cntT[2005], cntS[2005], dp[2005][2005], posSokwithT[2005];
bool isHaveAns(string s, string t){
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	return (s==t);
}

int solve(){
	memset(cntT,0,sizeof(cntT));
	memset(cntS,0,sizeof(cntS));
//	memset(dp,0,sizeof(dp)); LTE - ke ca cai cmt nay cung ton nhieu thoi gian :((
	memset(posSokwithT,0,sizeof(posSokwithT));
	cin >> n >> s >> t;
	if (!isHaveAns(s,t)) return -1;
	s = " " + s;
	t = " " + t;
	for (int i = 1; i <= n; i++){
		cntT[t[i]-'a']++;
		memset(cntS,0,sizeof(cntS));
		for (int j = 1; j <= n && ++cntS[s[j]-'a']<=cntT[s[j]-'a']; j++)
			posSokwithT[i] = j;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
		dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		if (s[i]==t[j]&&i<=posSokwithT[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
	}
	return n-dp[n][n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cout << solve() << '\n';
	}
}
