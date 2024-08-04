#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e3+5;
int n, c[maxN], f[maxN][maxN];
void solve(){
	cin >> n;
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		mp[a]++;
	}
	int m = 0;
	for (auto it: mp){
		c[++m] = it.second;
	}
	int res = 1e9;
	for (int i = 1; i <= n; i++) f[0][i] = 1e9;
	for (int i = 1; i <= m; i++){
		for (int j = 0; j <= n; j++){
			f[i][j] = 1e9;
			if (j>0) f[i][j] =f[i-1][j-1] + 1;
			if (j+c[i]<=n) f[i][j] = min(f[i][j],f[i-1][j-0+c[i]]);
//			cout << i << ", " << j << " = " << f[i][j] << "\n";
//			if (i==m&&f[i][j]>=j) res = min(res,f[i][j]);
			if (i==m) res = min(res,f[i][j]);
		}
	}
//	cout << f[m][0] << "\n";
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

