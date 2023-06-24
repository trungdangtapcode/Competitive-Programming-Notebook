#include <bits/stdc++.h>

using namespace std;
int dp[240000+5][105], n, a[1005];

int main(){
	freopen("CSC.INP","r",stdin);
	freopen("CSC.OUT","w",stdout);
	
	cin >> n;
	int res = 0, res_d, res_a;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--){
		for (int j = 0; j <= 100; j++){
			dp[a[i]+120000][j] = max(dp[a[i]+120000][j],dp[a[i]+j+120000][j]+1);
			if (res < dp[a[i]+120000][j]){
				res = dp[a[i]+120000][j];
				res_d = j;
				res_a = a[i];
			};
		}
	}
	cout << res << " " << res_d << '\n';
	for (int i = 0; i < res; i++) cout << res_a+res_d*i << '\n';
	
	return 0;
}
