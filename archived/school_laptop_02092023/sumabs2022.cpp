#include<bits/stdc++.h>

using namespace std;
int dp[55][10111][211];
int n, k, new_sum, new_inq;
const int t = 5005, u = 105;

int main(){
	cin >> n >> k;
//	for (int i = 0; i <= n; i++) dp[1][0+t][i+u] = 1;
	dp[1][0+t][0+u] = dp[1][1+t][1+u] = 1;
	for (int i = 1; i <= n; i++){
		for (int sum = -n*n; sum <= n*n; sum++){
			for (int inq = -n; inq <= n; inq++){
				//TH1:
				new_sum = sum + 2*i;
				new_inq = inq - 1;
				dp[i+1][new_sum+t][new_inq+u] += dp[i][sum+t][inq+u];
				//TH2:
				new_sum = sum;
				new_inq = inq;
				dp[i+1][new_sum+t][new_inq+u] += dp[i][sum+t][inq+u];
				//TH3:
				new_sum = sum;
				new_inq = inq;
				dp[i+1][new_sum+t][new_inq+u] += dp[i][sum+t][inq+u];
				//TH4:
				new_sum = sum;
				new_inq = inq;
				dp[i+1][new_sum+t][new_inq+u] += dp[i][sum+t][inq+u];
				//TH5:
				new_sum = sum-2*i;
				new_inq = inq+1;
				dp[i+1][new_sum+t][new_inq+u] += dp[i][sum+t][inq+u];
			}
		}
	}
	for (int i = 1; i <= n; i++){
		cout << i << ": \n";
		for (int j = -k; j <= k; j++){
			for (int jj = -n; jj <= n; jj++) cout << dp[i][j+t][jj+u] << "(" << j << "," << jj <<") ";
			cout << endl;
		}
		cout << endl;
	}
	
	cout << dp[n][k+t][0];	
	
	return 0;
}
