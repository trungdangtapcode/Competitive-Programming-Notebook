#include <bits/stdc++.h>

using namespace std;
int a[505], n, sum, dp[505][100005];
const int INF = 1e6;
int getDP(int k, int diff){
	if (diff>sum/2) return -INF;
	if (k>=n) return (diff!=0)*(-INF);
	if (dp[k][diff]!=-1) return dp[k][diff];
	dp[k][diff] = max({getDP(k+1,diff),
				getDP(k+1,diff+a[k])+a[k],
				getDP(k+1,abs(diff-a[k]))+max(a[k]-diff,0)
				});
	return dp[k][diff];
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	memset(dp,-1,sizeof(dp));
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	int res = getDP(0,0);
	int bonus = sum-2*res;
	cout << res+bonus;
	
	return 0;
}
