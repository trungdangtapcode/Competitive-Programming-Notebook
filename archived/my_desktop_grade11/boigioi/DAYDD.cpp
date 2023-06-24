#include <bits/stdc++.h>

using namespace std;
int n, a[1005], dp[1005][2],l,u;
int main(){
	//ifstream fi("MAXSEQ.INP");
	//ofstream fo("MAXSEQ.OUT");
	
	int n;
	cin >> n >> l >> u;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++){
		dp[i][0] = 1;
		for (int j = i-1; j >= 0; j--){
			if (a[i] - a[j] >= l&&a[i] - a[j] <= u) dp[i][0] = max(dp[i][0],dp[j][1]+1);
		}
		dp[i][1] = 1;
		for (int j = i-1; j >= 0; j--){
			if (a[j] - a[i] >= l&&a[j] - a[i] <= u) dp[i][1] = max(dp[i][1],dp[j][0]+1);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) res = max(res,max(dp[i][0],dp[i][1]));
	cout << res;
	
	//fi.close();
	//fo.close();
	
	
	
	return 0;
}
