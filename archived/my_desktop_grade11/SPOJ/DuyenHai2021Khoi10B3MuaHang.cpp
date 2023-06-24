#include <bits/stdc++.h>

using namespace std;
int n;
vector <vector <int>> a;
long long int dp[3005][3005][2];

bool cmp(vector<int> a, vector<int> b){
	return (a[1]-a[0]<b[1]-b[0]);
}
const long long int INF = 1e15;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	a.resize(n,vector<int>(3));
	for (int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	sort(a.begin(),a.end(),cmp);
	
	for (int i = 1; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j <= i; j++) for (int k = 0; k < 2; k++) if (dp[i][j][k]!=INF){
		dp[i+1][j][1] = min(dp[i+1][j][1],dp[i][j][k]+a[i][0]); //mua a[i+1]
		if (k==0) dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][k]+a[i][1]-(i-j)); //mua b[i+1]
		dp[i+1][j+1][k] = min(dp[i+1][j+1][k],dp[i][j][k]+a[i][2]-j); //mua c[i+1]
	}
	long long int res = INF;
	for (int i = 0; i <= n; i++) res = min({res,dp[n][i][0],dp[n][i][1]});
	cout << res;
	
	return 0;
}


//		dp[i][j][k] = 1e15;
//		if (k==1) dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][0]+a[i][0]);
//		if (k==0) dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][1]+a[i][1]-(i-1-j));
//		dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-1][k]-j-1)
