#include <bits/stdc++.h>

using namespace std;
long long int p = 1e9 + 7;
long long int dp[1005][1005];
int h, w;
bool isRong[1005][1005];
int main(){
	cin >> h >> w;
	for (int i = 1; i <= h; i++){
		string s; 
		cin >> s;
		for (int j = 0; j < s.length(); j++) isRong[i][j+1] = (s[j]=='.');
	}
//	for (int i = 1; i <= h; i++){
//		for (int j = 1; j <= w; j++) cout << isRong[i][j] << " ";
//		cout << endl;
//	}
	memset(dp,0,sizeof(dp));
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++) if (isRong[i][j]){
			if (i==1&&j==1) {dp[1][1] = 1; continue;}
			dp[i][j] = (dp[i-1][j] + dp[i][j-1])%p;
		}
	}
//	for (int i = 1; i <= h; i++){
//		for (int j = 1; j <= w; j++) cout << dp[i][j] <<
//	}
	cout << dp[h][w] << endl;
	
	return 0;
}
