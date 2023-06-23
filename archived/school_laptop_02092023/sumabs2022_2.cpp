#include<bits/stdc++.h>

using namespace std;
int dp[55][10111][55];
int n, k, new_sum, new_inq;
const int t = 5005;
const int p = 1e9+7;

int main(){
	cin >> n >> k;
//	for (int i = 0; i <= n; i++) dp[1][0+t][i+u] = 1;
	dp[1][0+t][0] = dp[1][-2+t][1] = 1;
	for (int i = 2; i <= n; i++){
		for (int sum = -n*n; sum <= n*n; sum++){
			for (int inq = 0; inq <= n; inq++){
				//TH1: hai ben noi len -> xu li inq; co (inq)^2 lua chon vi chon theo cap (quy tac nhan)
				if (inq>0){
					new_sum = sum + 2*i;
					new_inq = inq - 1;
					dp[i][new_sum+t][new_inq] += 1ll*dp[i-1][sum+t][inq]*inq*inq%p;
					dp[i][new_sum+t][new_inq] %= p;
//					if (new_inq==0&&dp[i-1][sum+t][inq]!=0&&i==2) cout << new_sum << " " << sum << endl;
				}
				//TH2, 3: mot trong hai -> co (1*inq)C1+(1*inq)C1 lua chon vi chon don le (quy tac cong)
				if (inq>0){
					new_sum = sum;
					new_inq = inq;
					dp[i][new_sum+t][new_inq] += 2ll*dp[i-1][sum+t][inq]*inq%p;
					dp[i][new_sum+t][new_inq] %= p;
				}
				//TH4: noi song song
				new_sum = sum;
				new_inq = inq;
				dp[i][new_sum+t][new_inq] += dp[i-1][sum+t][inq];
				dp[i][new_sum+t][new_inq] %= p;
				//TH5: noi xuong -> them inq
				new_sum = sum-2*i;
				new_inq = inq+1;
				dp[i][new_sum+t][new_inq] += dp[i-1][sum+t][inq];
				dp[i][new_sum+t][new_inq] %= p;
			}
		}
	}
//	for (int i = 1; i <= n; i++){
//		cout << i << ": \n";
//		for (int j = -n*n; j <= n*n; j++){
//			for (int jj = 0; jj <= n; jj++) cout << dp[i][j+t][jj] << "(" << j << "," << jj <<") ";
//			cout << endl;
//		}
//		cout << endl;
//	}
	
	cout << dp[n][k+t][0];	
	
	return 0;
}
