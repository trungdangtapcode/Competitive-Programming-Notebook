#include <bits/stdc++.h>
int n, k;
int INF = 1e6;
bool chan[505][505] = {false};
bool dp[505][505][1010][2] = {false};

using namespace std;int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//memset(dp,-1,sizeof(dp));
	
	cin >> n >> k;
	for (int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		chan[a][b] = true;
	}
	
	dp[1][1][0][0] = true;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) if (!chan[i][j]){
			for (int step = 1; step <= 2*n; step++){
				dp[i][j][step][0] = dp[i-1][j][step-1][0]||dp[i][j-1][step-1][0];
				if (!chan[i-1][j]||!chan[i][j-1]) dp[i][j][step][0] |= dp[i-1][j-1][step-1][0];
			} 
		}
	}
	dp[1][n][0][1] = true;
	for (int i = 1; i <= n; i++){
		for (int j = n; j >= 1; j--) if (!chan[i][j]){
			for (int step = 1; step <= 2*n; step++){
				dp[i][j][step][1] = dp[i-1][j][step-1][1]||dp[i][j+1][step-1][1];
				if (!chan[i-1][j]||!chan[i][j+1]) dp[i][j][step][1] |= dp[i-1][j+1][step-1][1];
			}
		}
	}
//	for (int step = 0; step <= 2*n; step++){
//		cout << "step: " << step << endl;
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= n; j++) cout << dp[i][j][step][1] << " ";
//			cout << endl;
//		}
//	}
	int res = INF;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) if (!chan[i][j]){
			for (int step = 1; step <= 2*n; step++){
				if (dp[i][j][step][0]&&dp[i][j][step][1]) res = min(res,step);
			} 
		}
	}
	cout << res;
	
	return 0;
}
