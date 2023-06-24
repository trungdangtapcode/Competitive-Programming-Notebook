#include <bits/stdc++.h>

using namespace std;
int dp[(1<<21)+5], a[25][25], n;
const int p = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	
	dp[0] = 1;
	for (int mask = 1; mask < (1<<n); mask++){
		int cnt = __builtin_popcount(mask); //cnt >0 
		for (int i = 0; i < n; i++) if ((mask&(1<<i))&&(a[cnt-1][i])){
			dp[mask] = (dp[mask]+dp[mask^(1<<i)])%p;
		}
	}
	cout << dp[(1<<n)-1];
	
	return 0;
}
