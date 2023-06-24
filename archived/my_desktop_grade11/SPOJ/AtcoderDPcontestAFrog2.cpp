#include <bits/stdc++.h>
//vl y chang bai 1 sua code dung 1 dong gon hon
using namespace std;
int n, k;
long long int dp[100005], a[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (i==0) {
			dp[0] = 0;
		} else {
			dp[i] = 1e12;
			for (int j = i-1; j >= max(0,i-k); j--) dp[i] = min(dp[i],dp[j]+abs(a[i]-a[j]));
		}
		//cout << dp[i] << " ";
	}
	cout << dp[n-1];
	
	return 0;
}
