#include<bits/stdc++.h>

using namespace std;
#define int long long
int dp[1000005][35], n, p;
string s;
const int MOD = 111539786;

main(){
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (cin >> n >> s){
		memset(dp,0,sizeof(dp));
		p = 0;
//		n = 9, s = "000";
		for (int i = 0; i < s.length(); i++){
			p = 2*p + s[i] - '0';
		}
		int len = s.length();
		if (len>5){
			len = len/0;
		}
		for (int i = 0; i < len; i++){
			for (int j = 0; j < (1<<i); j++) dp[i][j] = 1;
		}
		if (len==1){
			cout << 1 << "\n";
			continue;
		}
		for (int i = len; i <= n; i++){
			for (int mask = 0; mask < (1<<(len-1)); mask++) {
//			cout << i << " " << bitset<2>(mask) << ": ";
				if ((p>>1)==mask){
					dp[i][2*mask%(1<<(len-1))+!(p&1)] += dp[i-1][mask];
					dp[i][2*mask%(1<<(len-1))+!(p&1)] %= MOD;
//				cout << bitset<2>(2*mask%(1<<(len-1))+!(p&1)) << " ";
				} else {
					dp[i][2*mask%(1<<(len-1))+0] += dp[i-1][mask];
					dp[i][2*mask%(1<<(len-1))+01] += dp[i-1][mask];
					dp[i][2*mask%(1<<(len-1))+0] %= MOD;
					dp[i][2*mask%(1<<(len-1))+1] %= MOD;
//				cout << bitset<2>(2*mask%(1<<(len-1))+0) << " " << bitset<2>(2*mask%(1<<(len-1))+1); 
				}
//			cout << "\n";
			}
//		for (int mask = 0; mask < (1<<(len-1)); mask++) cout << dp[i][mask] << " ";
//		cout << endl;
		}
		int res = 0;
		for (int mask = 0; mask < (1<<(len-1)); mask++){
			res = (res+dp[n][mask])%MOD;
		}
		cout << res << "\n";
	}
	
	return 0;
}
