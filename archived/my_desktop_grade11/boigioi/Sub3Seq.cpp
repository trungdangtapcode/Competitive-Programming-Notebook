#include <bits/stdc++.h>

using namespace std;

int n, m, l, dp[105][105][105], a[105], b[105], c[105];

int main(){
	
	ifstream fi("Sub3Seq.inp");
	ofstream fo("Sub3Seq.out");
	
	string s;
	getline(fi,s);  if (s[s.length()-1]!=' ') s = s + ' '; n = 0;
	for (int i = 0, j = 0; i < s.length(); i++){
		if (s[i]==' ') a[++n] = stoi(s.substr(j,i-j)), j = i+1;
	}
	getline(fi,s); if (s[s.length()-1]!=' ') s = s + ' '; m = 0; //ko can ignore
	for (int i = 0, j = 0; i < s.length(); i++){
		if (s[i]==' ') b[++m] = stoi(s.substr(j,i-j)), j = i+1;
	}
	getline(fi,s); if (s[s.length()-1]!=' ') s = s + ' '; l = 0;
	for (int i = 0, j = 0; i < s.length(); i++){
		if (s[i]==' ') c[++l] = stoi(s.substr(j,i-j)), j = i+1;
	}
	//for (int i = 0; i < n; i++) cout << a[i] << " ";
	//for (int i = 1; i <= m; i++) cin >> b[i];
	
	memset(dp,0,sizeof(dp));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			for (int k = 1; k <= l; k++){
				if (a[i]==b[j]&&b[j]==c[k]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				else dp[i][j][k] = max({dp[i][j-1][k],dp[i-1][j][k],dp[i][j][k-1]});	
			}
		}
	}
	
	fo << dp[n][m][l];
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	fi.close();
	fo.close();
	
	return 0;
}
