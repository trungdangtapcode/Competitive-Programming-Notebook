#include <bits/stdc++.h>
int n, k;
int INF = 1e6;
bool chan[505][505] = {false};

using namespace std;

bitset<1010> dp[505][505][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		chan[a][b] = true;
	}
	
	dp[1][1][0][0] = 1;
	//cout << dp[1][1][0][0] << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) if (!chan[i][j]){
			if (i==1&&j==1) ;else
			dp[i][j][0] = (dp[i-1][j][0]|dp[i][j-1][0]|dp[i-1][j-1][0]), dp[i][j][0] <<= 1;
		} else dp[i][j][0] = 0;
	}
	dp[1][n][1][0] = true;
	for (int i = 1; i <= n; i++){
		for (int j = n; j >= 1; j--) if (!chan[i][j]){
			if (i==1&&j==n) ;else
			dp[i][j][1] = (dp[i-1][j][1]|dp[i][j+1][1]|dp[i-1][j+1][1]), dp[i][j][1] <<= 1;
		} else dp[i][j][1] = 0;
	}
//	for (int step = 0; step <= 2*n; step++){
//		cout << "step: " << step << endl;
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= n; j++) cout << dp[i][j][0][step] << " ";
//			cout << endl;
//		}
//	}
	int res = INF;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) if (!chan[i][j]){
			for (int step = 1; step <= 2*n; step++){
				if (dp[i][j][0][step]&&dp[i][j][1][step]) {res = min(res,step); break;} //co cach cai tien tot hon break nhung AC roi thoi ke :_)
			} 
		}
	}
	cout << res;
	return 0;
}
