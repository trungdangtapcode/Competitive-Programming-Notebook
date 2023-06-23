#include<bits/stdc++.h>

using namespace std;
int dp[75][75][45][75], n, m, k, a[75][75];
int f(int i, int j, int c, int v){
	if (i==n+1) return (v==0?0:-1e9);
	if (dp[i][j][c][v]!=-1) return dp[i][j][c][v];
//	int &res = dp[i][j][c][v] = 0; -1e9 because maybe it -INF at the end so default is 0 is wrong
	int ni = i, nj = j+1;
	if (nj==m+1) nj = 1, ni++;
//	res = max(res,f(ni,nj,(nj==1?0:c),v));
	int &res = dp[i][j][c][v] = f(ni,nj,(nj==1?0:c),v);
	if (c<m/2) res = max(res,f(ni,nj,(nj==1?0:c+1),(v+a[i][j])%k)+a[i][j]);
	return res;
}

int main(){
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int ii = 0; ii <= m/2; ii++) for (int jj = 0; jj < k; jj++) dp[i][j][ii][jj] = -1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
	cout << f(1,1,0,0);
	
	return 0;
}
