#include<bits/stdc++.h>

using namespace std;
int n, dp[505][505];
string s;
const int p = 1e9+7;
int f(int x, int y){
	if (y-x+1==0) return 1;
	if (y-x+1==1) return 0;
	if (dp[x][y]!=-1) return dp[x][y];
	int& res = dp[x][y] = 0;
	for (int i = x+1; i <= y; i++){
		if (s[x]=='?'&&s[i]=='?') (res += 3ll*f(x+1,i-1)*f(i+1,y)%p) %= p;
		else if ((s[x]=='?'||s[x]=='(')&&(s[i]=='?'||s[i]==')')||(s[x]=='?'||s[x]=='[')&&(s[i]=='?'||s[i]==']')||(s[x]=='?'||s[x]=='{')&&(s[i]=='?'||s[i]=='}'))
			(res += 1ll*f(x+1,i-1)*f(i+1,y)%p) %= p;
	}
	return res;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin >> s;
	n = s.length();
	s = "#" + s;
	cout << f(1,n);
	
	return 0;
}
