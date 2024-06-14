#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, f[105], mfi;
map<int,int> memo[105];
int dp(int n, int j){
//	cout << n << " " << j << '\n';
	if (n==1) return 1;
	if (memo[j].count(n)) return memo[j][n];
	int &res = memo[j][n];
	res = 0;
	for (int i = j; i <= mfi; i++) if (n%f[i]==0){
		res += dp(n/f[i],i);
	}
	return res;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	f[0] = f[1] = 1;
	for (int i = 2; i <= 100; i++){
		f[i] = f[i-1] + f[i-2];
//		cout << f[i] << " ";
//		cout << i << "\n";
		mfi = i;
		if (f[i]>1e18) break;
	}
	int t; cin >> t;
	while (t--){
		cin >> n;
		cout << dp(n,2) << "\n";
	}
		
	return 0;
}
