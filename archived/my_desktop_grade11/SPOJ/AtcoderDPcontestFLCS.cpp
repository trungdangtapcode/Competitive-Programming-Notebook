#include <bits/stdc++.h>

using namespace std;
int n, m;
string s, t;
int dp[3005][3005];
//pair<int, int> trace[1005][1005];
//bool usedS[1005];
int main(){
	cin >> s >> t;
	n = s.length();
	m = t.length();
	s = " " + s;
	t = " " + t;
	
	memset(dp,0,sizeof(dp));
	//memset(usedS,false,sizeof(usedS));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i][j] = (s[i]==t[j]?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1])); //nen lay ben chuoi nao day
		}
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++){
//			cout << dp[i][j];
//		}
//		cout << endl;
//	}
//	cout << dp[n][m] << endl;
	int x = n, y = m;
	vector <char> res;
	while (true){
		if (s[x]==t[y]) res.push_back(s[x]), x--, y--;	
		 else if (dp[x-1][y]>dp[x][y-1]) x--; else y--;
		if (x==0||y==0) break;
	}
	reverse(res.begin(),res.end());
	for (auto& it: res) cout <<it;
	
	return 0;
}
