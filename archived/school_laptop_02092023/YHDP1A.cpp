#include<bits/stdc++.h>
using namespace std;

int c[200005], n, dp[200005][2];// jprv[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> c[i];
		for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = 0;
		for (int i = 1; i <= n; i++) dp[c[i]][i&1] = dp[c[i]][!(i&1)] + 1;
		for (int i = 1; i <= n; i++) cout << max(dp[i][0],dp[i][1]) << " ";
		cout << "\n";
	}
	
	return 0;
}
