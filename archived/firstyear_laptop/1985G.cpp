#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9+7;
int getpow(int a, int n){
	int res = 1;
	while (n>0){
		if (n%2) (res *= a)%=mod;
		(a *= a)%=mod;
		n /= 2;
	}
	return res;
}

void solve(){
	int l, r,k;
	cin >> l >> r >> k;
	int res = getpow(9/k+1,r)-getpow(9/k+1,l);
	res %= mod;
	if (res<0) res += mod;
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

