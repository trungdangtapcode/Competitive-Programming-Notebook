#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5, mod = 1e9+7;
int f[maxN], n, k, x[maxN], y[maxN];
void solve(){
	cin >> n >> k;
	int n0 = n;
	for (int i = 1; i <= k; i++){
		cin >> x[i] >> y[i];
		n0 -= (x[i]==y[i]?1:2);
	}
//	cout << n0 << "\n";
	f[0] = f[1] = 1;
	for (int i = 2; i <= n0; i++){
//		(f[i] = 1ll*f[i-1]*(i-1)%mod + 1ll*f[i-2]*i%mod*(i-1)%mod)%=mod;
		(f[i] = f[i-1]+2ll*(i-1)*f[i-2]%mod)%=mod;
	};
	cout << f[n0] << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

