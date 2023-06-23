#include<bits/stdc++.h>

using namespace std;
int dp[2005][1<<10]; //00: ko co, 01: (, 10: [, 11: { 
int n, k;
string s;
const int p = 1e9+7;

string in(int x){
	string res = "|";
	while (x){
		if (x%4==0) return res;
		if (x%4==1) res.push_back('(');
		if (x%4==2) res.push_back('[');
		if (x%4==3) res.push_back('{');
		x /= 4;
	}
	return res;
}

int solve(int n, int k, string s){
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) for (int mask = 0; mask < 1<<(2*k); mask++){
		if (dp[i-1][mask]==0) continue;
//		cout << i-1 << " " << in(mask) << " -> " << dp[i-1][mask] << endl;
		if (mask>>2*k-2==0){ //mo ngoac
			if (s[i]=='('||s[i]=='?') dp[i][(mask<<2)+1] += dp[i-1][mask], dp[i][(mask<<2)+1] %= p;
			if (s[i]=='['||s[i]=='?') dp[i][(mask<<2)+2] += dp[i-1][mask], dp[i][(mask<<2)+2] %= p;
			if (s[i]=='{'||s[i]=='?') dp[i][(mask<<2)+3] += dp[i-1][mask], dp[i][(mask<<2)+3] %= p;
		}
		//dong ngoac
		if ((s[i]==')'||s[i]=='?')&&(mask&3)==1) dp[i][mask>>2] += dp[i-1][mask], dp[i][mask>>2] %= p;
		if ((s[i]==']'||s[i]=='?')&&(mask&3)==2) dp[i][mask>>2] += dp[i-1][mask], dp[i][mask>>2] %= p;
		if ((s[i]=='}'||s[i]=='?')&&(mask&3)==3) dp[i][mask>>2] += dp[i-1][mask], dp[i][mask>>2] %= p;
	}
	return dp[n][0];
}

int main(){
	
	cin >> n >> k >> s;
	s = "#"+s;
	cout << (solve(n,k,s)-solve(n,k-1,s) + 1ll*p*p)%p;
	
	return 0;
}
