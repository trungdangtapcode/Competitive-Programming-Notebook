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
	for (int i = 0; i < n; i++){
		dp[i][i] = dp[i+1][i] = true;
		for (int j = i-1; j >= 0; j--){
			dp[j][i] = (dp[j+1][i-1]&&s[j]==s[i]&&s[j]!='0');
			cout << j << " " << i << " " << dp[j][i] << '\n';
			if (dp[j][i]) res++;
		}
	}
	cout << res;
	return 0;
}
