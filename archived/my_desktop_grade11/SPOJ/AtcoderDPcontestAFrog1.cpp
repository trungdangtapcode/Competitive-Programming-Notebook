#include <bits/stdc++.h>

using namespace std;
int n;
int dp[100005], a[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (i==0) {
			dp[0] = 0;
		} else if (i==1){
			dp[1] = abs(a[1]-a[0]);
		} else {
			dp[i] = min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
		}
	}
	cout << dp[n-1];
	
	return 0;
}
