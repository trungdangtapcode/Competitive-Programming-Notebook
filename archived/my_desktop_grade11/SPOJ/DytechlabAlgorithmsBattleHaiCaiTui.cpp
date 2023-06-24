#include <bits/stdc++.h>

using namespace std;
int dp[5005][5005], w[5005], n;
void bfs(){
	queue<pair<int,int>> q;
	q.push({0,0});
	dp[0][0] = 0;
	while (!q.empty()){
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if (dp[i][j]==n) continue;
		int i2 = i+w[dp[i][j]];
		int j2 = j+w[dp[i][j]];
//		cout << i << " " << j << " " << i2 << " " << j2 << endl;
		if (j2<=5000&&dp[i][j2]==-1) {
			dp[i][j2] = dp[i][j] + 1;
			q.push({i,j2});
		}
		if (i2<=5000&&dp[i2][j]==-1) {
			dp[i2][j] = dp[i][j] + 1;
			q.push({i2,j});
		}
	}
	return;
}
void enlarge(){
	//mo rong theo chieu ngang
	for (int i = 0; i <= 5000; i++){
		for (int j = 0; j < 5000; j++){
			if (dp[i][j+1]==-1&&dp[i][j]!=-1) dp[i][j+1] = dp[i][j];
		}
	}
	//mo rong theo chieu doc
	for (int i = 0; i <= 5000; i++){
		for (int j = 0; j < 5000; j++){
			if (dp[j+1][i]==-1&&dp[j][i]!=-1) dp[j+1][i] = dp[j][i];
		}
	}
}
long long int calc(){
	long long int res = 0;
	for (int i = 1; i <= 5000; i++){
		for (int j = 1; j <= 5000; j++) res += dp[i][j]^i^j;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	memset(dp,-1,sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i];
	sort(w,w+n);
	bfs();
	enlarge();
	cout << calc();
//	for (int i = 0; i <= 16; i++){
//		for (int j = 0; j <= 16; j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	
	return 0;
}
