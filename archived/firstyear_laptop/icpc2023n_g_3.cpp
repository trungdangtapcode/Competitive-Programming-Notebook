#include<bits/stdc++.h>

using namespace std;
string s;
int n, k, f[200005][15], prv[200005], last[26];
const int p = 1e9+7;
int main(){
	cin >> n >> k >> s;
	s = "#" + s;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++){
		prv[i] = last[s[i]-'a'];
		last[s[i]-'a'] = i;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= k; j++){
			f[i][j] = f[i-1][j];
			if (j) (f[i][j] += f[i-1][j-1])%=p;
			int u = prv[i];
			int jj = j - (i-u);
			if (u&&jj>=0) (f[i][j] -= f[u-1][jj])%=p;
		}
	}
	cout << (f[n][k]+p)%p;
	
	return 0;
}
