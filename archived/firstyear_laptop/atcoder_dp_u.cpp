#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 16;
int n, a[maxN][maxN], dp[(1<<maxN)+5], solved[(1<<maxN)+5];
int calc(int mask){
	if (solved[mask]!=-1e18) return solved[mask];
	int sum = 0;
	for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) if ((mask>>i&1)&&(mask>>j&1)){
		sum += a[i][j];
	} 
	return solved[mask] = sum;
}
int f(int mask){
	if (mask==0) return 0;
	if (dp[mask]!=-1e18) return dp[mask];
	for (int sub = mask; sub; sub = (sub-1)&mask){
//		cout << bitset<3>(mask) << " sub = " << bitset<3>(sub) << "\n";
		dp[mask] = max(dp[mask],f(mask^sub)+calc(sub));
	}
//	cout << bitset<3>(mask) << " " << dp[mask] << "\n";
	return dp[mask];
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	for (int mask = 0; mask < (1<<n); mask++) dp[mask] = solved[mask] = -1e18;
	cout << f((1<<n)-1);
	
	return 0;
}
