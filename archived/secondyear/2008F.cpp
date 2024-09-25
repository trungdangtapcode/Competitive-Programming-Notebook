#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5, mod = 1e9+7;;
int n, a[maxN];
int inv(int x){
	int b = mod-2, res = 1;
	while (b){
		if (b%2) res = 1ll*res*x%mod;
		x = 1ll*x*x%mod;
		b >>= 1;
	}
	return res;
}
void solve(){
	cin >> n;
	for (int i = 1; i<= n; i++) cin >> a[i];
	int inv2 = (mod-mod/2);
//	int sum = accumulate(a+1,a+n+1,0ll);
	int sum = 0;
	for (int i = 1; i<= n; i++) (sum += a[i])%=mod;
	sum = 1ll*sum*sum%mod;
	for (int i = 1; i<= n; i++) (sum -= 1ll*a[i]*a[i]%mod)%=mod;
	sum = 1ll*sum*inv2%mod;
	sum = 1ll*sum*inv(1ll*n*(n-1)/2%mod)%mod;
	(sum += mod)%=mod;
	cout << sum << '\n';
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

