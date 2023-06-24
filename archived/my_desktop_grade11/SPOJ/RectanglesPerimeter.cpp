#include <bits/stdc++.h>

using namespace std;
int n;
typedef pair<int, int> id;
vector <id> a;
int dp[5000][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	cin >> n;
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		a.push_back({x,y});
	}
	
	dp[0][0] = a[0].first;
	dp[0][1] = a[0].second;
	for (int i = 1; i < n; i++){
		dp[i][0] = max(dp[i-1][0]+abs(a[i-1].second-a[i].second),dp[i-1][1]+abs(a[i-1].first-a[i].second))+a[i].first;
		dp[i][1] = max(dp[i-1][0]+abs(a[i-1].second-a[i].first),dp[i-1][1]+abs(a[i-1].first-a[i].first))+a[i].second;
	}
	
//	for (int i = 0; i < n; i++){
//		cout << dp[i][0] << " " << dp[i][1] << endl;
//	}
	cout << max(dp[n-1][0],dp[n-1][1]);
	
	return 0;
}
