#include <bits/stdc++.h>

using namespace std;
string s;
int dp[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> s;
		for (int i = 0; i < s.length(); i++){
			if (s[i]=='0'){
				if (i>0) dp[i] = dp[i-1]; else dp[i] = 0; //{0} -> ok
				if (i==0) continue; //xet tap 2 phan tu
				if (s[i-1]=='1') //{10} -> ok
					if (i>1) dp[i] = min(dp[i],dp[i-2]); else dp[i] = min(dp[i],0);
			} else {
				if (i>0) dp[i] = dp[i-1] + 1; else dp[i] = 1; //{1} -> ded
				if (i==0) continue; //xet tap 2 phan tu
				if (s[i-1]=='0') //{01} -> ok
					if (i>1) dp[i] = min(dp[i],dp[i-2]); else dp[i] = min(dp[i],0);
			}
		}
		cout << dp[s.length()-1] << '\n';
	}
	
	
	return 0;
}
