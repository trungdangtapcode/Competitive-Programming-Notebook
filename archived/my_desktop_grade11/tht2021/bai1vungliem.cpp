#include<bits/stdc++.h>

using namespace std;
int n;
string s;
bool dp[2005][2005];

int main(){
	//freopen("bai4.inp","r",stdin);
	//freopen("bai4.out","w",stdout);
	int res = 0;
	cin >> s;
	n = s.length();
	for (int i = 1; i < n-1; i++){
		res += (s[i-1]!='0'&&s[i-1]==s[i+1]);
	}
	cout << res;
	return 0;
}
