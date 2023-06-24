#include <bits/stdc++.h>

using namespace std;
int n, t;
int p[4] = {2,3,5,7};
int dp[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//memset(dp,1,sizeof(dp));
	for (int i = 0; i <= 1e6; i++) dp[i] = 1e6+5;
	
	dp[0] = 0; 
	//dp[2] = dp[3] = dp[5] = dp[7] = 1;
	for (int i = 0; i <= 1e6; i++){
		for (int j = 0; j < 4; j++) if (i>=p[j]){
			//cout << i << " " << dp[i] << endl;
			dp[i] = min(dp[i],dp[i-p[j]]+1);
		}
		//cout << i << " " << dp[i] << endl;
	}
	
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n;
		cout << (dp[n]==1e6+5?-1:dp[n]) << '\n';
	}
	
	return 0;
}
