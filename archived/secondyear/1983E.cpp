#include<bits/stdc++.h>

using namespace std;
const int maxN = 4e5+5, mod = 1e9+7;
int n, a[maxN], k;
int getpow(int a, int n){
	int res = 1;
	while (n>0){
		if (n%2) res = 1ll*res*a%mod;
		a = 1ll*a*a%mod;
		n /= 2;
	}
	return res;
}
int inv(int x){
	return getpow(x, mod-2);
}

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int avg_non = 0, avg_spe = 0;
	for (int i = 1; i <= k; i++) (avg_spe += a[i])%= mod;
	avg_spe = 1ll*avg_spe*inv(k)%mod;
	for (int i = k+1; i <= n; i++) (avg_non += a[i])%=mod;
	avg_non = 1ll*avg_non*inv(n-k)%mod;
	int e_spe_alice = 1ll*(n-k+2)/2*k%mod*inv(n-k+1)%mod*avg_spe%mod;
	int e_non_alice = 1ll*(n-k+1)/2*avg_non%mod;
	cout << (e_spe_alice+e_non_alice)%mod << " ";
	int e_spe_bob = (k-1ll*(n-k+2)/2*k%mod*inv(n-k+1)%mod+mod)*avg_spe%mod;
	int e_non_bob = 1ll*(n-k-(n-k+1)/2)*avg_non%mod;
	cout << (e_spe_bob+e_non_bob)%mod << "\n";
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

