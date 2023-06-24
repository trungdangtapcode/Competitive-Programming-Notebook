#include <bits/stdc++.h>

using namespace std;
int f[270005], dp[270005][65], n, a[270005];

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	memset(dp,-1,sizeof(dp));
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], dp[i][a[i]] = i;
	for (int i = 1; i <= 60; i++){
		for (int j = 1; j <= n; j++){
			if (dp[j][i]!=-1) continue; //dp
			if (dp[j][i-1]==-1) continue; // = -1; nham ==1)
			dp[j][i] = dp[dp[j][i-1]+1][i-1];
		}
	}
	
//	for (int i = 1; i <= 4; i++) {
//		cout << i << ": \n";
//		for (int j = 1; j <= n; j++) cout << dp[j][i] << " ";
//		cout << endl;
//	}
		
	f[n+1] = 0;
	for (int i = n; i >= 1; i--){
//		f[i] = a[i];
		for (int j = 1; j <= 60; j++) if (dp[i][j]!=-1){
			f[i] = max(f[i],max(f[dp[i][j]+1],j));
		}
	}
	cout << f[1]; //f[1] // *max_element(f+1,f+n+1)
	return 0;
}
