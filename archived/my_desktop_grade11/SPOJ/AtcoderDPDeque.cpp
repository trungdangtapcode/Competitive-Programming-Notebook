#include <bits/stdc++.h>
#define fix cout<<"fix"<<endl;
using namespace std;
int n;
vector<long long int> a (3005);
long long int dp[3005][3005][2];
long long int dp_set(int x, int y, int play){
	if (x>y) return 0;
	//cout << x << " " << y << " "<< play<<  endl;
	if (dp[x][y][play] != -1) return dp[x][y][play];
	if (play == 0){
		dp[x][y][play] = max(dp_set(x,y-1,1)+a[y],dp_set(x+1,y,1)+a[x]);
		return dp[x][y][play];
	} else {
		dp[x][y][play] = min(dp_set(x,y-1,0),dp_set(x+1,y,0));
		return dp[x][y][play];
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << dp_set(0,n-1,0) - dp_set(0,n-1,1);
}
