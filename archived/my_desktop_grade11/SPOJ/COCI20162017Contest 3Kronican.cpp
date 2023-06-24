#include <bits/stdc++.h>

using namespace std;
int n, k, a[25][25], dp[1<<21];
int getDP(int mask){
	if (__builtin_popcount(mask)==k) return 0;
	if (dp[mask]!=-1) return dp[mask];
	int res = 1e9 + 7;
	for (int i = 0; i < n; i++) if (mask&(1<<i))
		for (int j = 0; j < n; j++) if ((mask&(1<<j))&&i!=j)
			res = min(res,getDP(mask^(1<<i))+a[i][j]);
	dp[mask] = res;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin >> n >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	cout << getDP((1<<n)-1);
	
	return 0;
}
