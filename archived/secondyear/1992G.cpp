#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e3+5, mod = 1e9+7;
int n, fact[maxN], inv[maxN];
int nCr(int n, int r){
	if (r<0) return 0;
	if (n<0){
//		if (r==0) cout << "hi\n";
		if (r==0) return 1;
		return 0;
	}
	if (r>n) return 0;
	return 1ll*fact[n]*inv[r]%mod*inv[n-r]%mod;
}
void solve(){
	cin >> n;
	long long int res = 0;
	for (int i = 1; i <= 2*n+1; i++){
		for (int j = 0; j <= n; j++){
			int cnt = i-1-j; //empty balls
			if (cnt<0||cnt-j<0) continue;
//			cout << n-i << "\n";
			(res += 1ll*nCr(min(i-1,n),j)*nCr(n-i,cnt-j)%mod*i%mod)%=mod;
		}
	}
	cout << res << "\n";
//	exit(0);
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int n = 5000;
	fact[0] = fact[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= n; i++) fact[i] = 1ll*fact[i-1]*i%mod;
	for (int i = 2; i <= n; i++) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
	for (int i = 2; i <= n; i++) inv[i] = 1ll*inv[i-1]*inv[i]%mod;
	int t; cin >> t;
	while (t--)
	solve();
}

