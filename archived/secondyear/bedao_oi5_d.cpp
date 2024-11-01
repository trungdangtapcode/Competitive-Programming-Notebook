#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e3+5;
int palin[maxN][maxN], sl[maxN][maxN], sr[maxN][maxN], dp[maxN][maxN], n;
string s;
void solve(){
	cin >> n >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) palin[i][i] = palin[i][i-1] = 1;
	for (int i = n; i >= 1; i--){
		for (int j = i+1; j <= n; j++){
			if (s[i]==s[j]) palin[i][j] = palin[i+1][j-1];
		}
	}
	for (int i = 1; i <= n; i++){
		sl[i][i] = sr[i][i] = 1;
		for (int j = i+1; j <= n; j++) sl[i][j] = sl[i][j-1]+palin[i][j];
		for (int j = i-1; j >= 1; j--) sr[j][i] = sr[j+1][i]+palin[j][i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = n; j > i; j--) if (s[i]==s[j]){
			dp[i][j] = dp[i-1][j+1]+1;
		}
	}
	long long res = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i+2; j <= n; j++){
			long long cur = 1ll*dp[i][j]*(sl[i+1][j-1]+sr[i+1][j-1]);
			res += cur;
//			cur = 1ll*dp[i][j]*sr[i+1][j-1];
//			res += cur;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++) res += dp[i][j];
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#else
	freopen("vastr.inp","r",stdin);
	freopen("vastr.out","w",stdout);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

