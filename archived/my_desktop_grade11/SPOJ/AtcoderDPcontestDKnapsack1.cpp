#include <bits/stdc++.h>

using namespace std;

vector <long long int> v;
vector <int> w;
int S, n;
long long int dp[105][100005];
int main(){
	cin >> n >> S;
	w.push_back(-1); v.push_back(-1);
	for (int i = 0; i < n; i++) {
		int a;
		long long int b;
		cin >> a >> b;
		w.push_back(a);
		v.push_back(b);
	}
	
	memset(dp,0,sizeof(dp));
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= S; j++){
			//cout << i << " "<< j << endl;
			dp[i][j] = dp[i-1][j];
			if (j>=w[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
		}
	}
//	for (int i = 0; i <= n; i++){
//		for (int j = 0; j <= S; j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	cout << dp[n][S];
	
	return 0;
}
