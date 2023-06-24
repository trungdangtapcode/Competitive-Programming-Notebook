#include <bits/stdc++.h>
//vl y chang bai 1 sua code dung 1 dong gon hon
using namespace std;
int n, k;
long long int dp[100005][3], a[3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[0] >> a[1] >> a[2];
		if (i == 0) {
			for (int j = 0; j < 3; j++) dp[i][j] = a[j]; 
		} else for (int j = 0; j < 3; j++) {
			dp[i][j] = 0;
			for (int k = 0; k < 3; k++) if (k!=j){
				dp[i][j] = max(dp[i][j],dp[i-1][k]+a[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) cout << dp[i][j] << " ";
		cout << endl;
	}
	cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	
	return 0;
}
