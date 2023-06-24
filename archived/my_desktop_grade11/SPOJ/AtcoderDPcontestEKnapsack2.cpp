#include <bits/stdc++.h>

using namespace std;
long long int w; int v,n,S;
long long int dp[105][100005]; 
int main(){
	
	cin >> n >> S;
	for (int i = 0; i < n; i++){
		cin >> w >> v;
		dp[0][0] = 0; 
		if (i == 0){
			for (int j = 1; j <= 100000; j++) dp[0][j] = 1e12;
			dp[0][v] = w;
			//dp[i][j] = 100000;
			//
		} else
		for (int j = 1; j <= 100000; j++){
			dp[i][j] = dp[i-1][j];
			if (j>=v) dp[i][j] = min(dp[i][j],dp[i-1][j-v]+w);
		}
	}
//	for (int j = 0; j < 20; j++){
//		for (int i = 0; i < n; i++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	for (int i = 100000; i >= 0; i--) if (dp[n-1][i]<=S){
		cout << i << endl;
		return 0;
	}
	return 0;
}
