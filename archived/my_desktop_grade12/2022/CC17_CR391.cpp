#include<bits/stdc++.h>

using namespace std;
int res, n, r, spf[1000005], f[21][1000005];
const int p = 1e9+7;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 1e6; i++) f[0][i] = 1;
	for (int i = 1; i <= 20; i++) f[i][0] = 2;
	for (int i = 1; i <= 20; i++){
		for (int j = 1; j <= 1e6; j++) f[i][j] = (f[i][j-1]+f[i-1][j])%p;
	}
	for (int i = 1; i <= 1e6; i++) spf[i] = i;
	for (int i = 2; i <= 1e6; i++) if (spf[i]==i) for (int j = min(1ll*i*i,1000001ll); j <= 1e6; j += i) spf[j] = i;
	int t; cin >> t;
	while (t--){
		cin >> r >> n;
		int res = 1;
		while (n>1){
			int d = spf[n], cur = 0;
			while (n%d==0) n /= d, cur++;
			res = 1ll*res*f[cur][r]%p;
		}
		cout << res << "\n";
	}
	
	return 0;
}
