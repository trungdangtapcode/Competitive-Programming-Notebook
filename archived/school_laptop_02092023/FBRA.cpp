#include<bits/stdc++.h>

using namespace std;
#define int long long
int f[1005][1005];
string s;
int n;
const int p = 1e9+7;
int g(int x, int y){
	if (f[x][y]!=-1) return f[x][y];
	int res = 0;
	for (int i = x+1; i <= y; i++){
//		for (int j = i-1; j > 0; j--){
		if (s[x]=='?'&&s[i]=='?') res = (res+g(x+1,i-1)*3%p*g(i+1,y)%p)%p;
		else if ((s[x]=='?'||s[i]=='?')&&(s[x]=='('||s[i]==')'||s[x]=='['||s[i]==']'||s[x]=='{'||s[i]=='}')) res = (res+g(x+1,i-1)*g(i+1,y)%p)%p;
		if (s[x]=='('&&s[i]==')'||s[x]=='['&&s[i]==']'||s[x]=='{'&&s[i]=='}') res = (res+g(x+1,i-1)*g(i+1,y)%p)%p;
	}
	return f[x][y] = res;
}

main(){
	cin >> s;
	n = s.length();
	s = "#" + s;
	for (int i = 0; i <= n+1; i++) for (int j = 0; j <= n+1; j++) f[i][j] = -1;
	for (int i = 1; i <= n+1; i++) f[i][i-1] = 1;
	cout << g(1,n);
	
	return 0;
}
