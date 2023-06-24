#include <bits/stdc++.h>

using namespace std;
int n;
int a[1005];
int segMax[1005][1005], segMin[1005][1005];
double c[1005][1005], theta;
int dp[1005][1005], maxDP[1005][1005], trace[1005][1005];

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	memset(dp,1,sizeof(dp));
	memset(trace,-1,sizeof(trace));
	
	cin >> n >> theta;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		segMax[i][i] = a[i];
		segMin[i][i] = a[i];
		dp[i][i] = 0;
		maxDP[i][i] = 0;
		trace[i][i] = 1;
	}	
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			segMax[i][j] = max(segMax[i][j-1],a[j]);
			segMin[i][j] = min(segMin[i][j-1],a[j]);
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			c[i][j] = (j-i+1.0)/(segMax[i][j]-segMin[i][j]+1.0);
		}
	}
	
	for (int l = 2; l <= n; l++){
		for (int i = 1, j = l; j <= n; i++, j++){
			if (c[i][j] >= theta) {dp[i][j] = 1; continue;}
			for (int k = i; k < j; k++) if (c[i][k]>=theta&&c[k+1][j]>=theta){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
			}
		}
	}
	cout << dp[1][n] << endl;
	//cout << c[1][1] << " " <<  << endl;
	
	return 0;
}
