//https://media.discordapp.net/attachments/1030096023328149509/1227734346295939172/image.png?ex=66297bb6&is=661706b6&hm=37960bd7a73da5f299632e1bce44e153a5c4c37b714c97ca907e42fbaa7018f9&=&format=webp&quality=lossless&width=1440&height=563
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e6+6, mod = 998244353;
int n, l, m, fact[maxN], inv[maxN];
int nCr(int n, int r){
	if (r<0||r>n) return 0;
	return fact[n]*inv[r]%mod*inv[n-r]%mod;
}
int pw(int a, int n){
	int res = 1;
	while (n){
		if (n%2) res = res*a%mod;
		a = a*a%mod;
		n /= 2;
	}
	return res;
}
void solve(){
	cin >> l >> n;
	m = l-2*n;
	int res = 0;
	for (int i = 0; i <= m; i += 2){
		res += nCr(i/2+n-1,n-1)*nCr(m-i+n,n)%mod;
		res %= mod;
	}
//	cout << res << "\n";
	cout << (nCr(m+2*n,2*n)-res+mod)*2%mod << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= 1e6; i++) fact[i] = fact[i-1]*i%mod;
	for (int i = 2; i <= 1e6; i++) inv[i] = (mod-mod/i)*inv[mod%i]%mod;
	for (int i = 2; i <= 1e6; i++) inv[i] = inv[i-1]*inv[i]%mod;
	int t; cin >> t;
	while (t--)
	solve();
}

/*
	for (int popcnt = 0; popcnt <= min(m,n); popcnt++){
//		if ((m-popcnt)%2) continue;
		if (popcnt%2==0) continue;
		int euler = (m-popcnt)/2;
		if (euler<0) continue;
		cout << popcnt << " " << nCr(n+1,popcnt)*nCr(euler+n,n) << "\n";
		res += nCr(n+1,popcnt)*nCr(euler+n,n)%mod;
		res %= mod;
	}	

*/

