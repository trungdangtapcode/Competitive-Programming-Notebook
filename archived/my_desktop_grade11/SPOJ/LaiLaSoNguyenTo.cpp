#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

 
ll powmod(ll a, ll b, ll n) {
	if(b == 0) return 1;
	ll res = powmod(a, b/2, n);
	return (b%2==1) ? (((res*res)%n)*a)%n : ((res*res)%n);
}
 
bool MillerTest(ll n, ll s, ll m) {
	ll a = (ll) rand() % (n-2) + 2, b = powmod(a, m, n);
	ll pre = n-1;
	for (int i = s; i >= 0; i--) {
		if(b == 1) return pre == n-1;
		pre = b; b = (b*b) % n;
	}
	return 0;
}
 
bool prime(ll n) {
	if(n == 2) return 1;
	if(n % 2 == 0 || n < 2) return 0;
	ll s = 63 - __builtin_clzll((n-1)&(1-n)), m = (n-1) >> s;
	for(int k=0; k<30; ++k) 
		if(!MillerTest(n, s, m)) return 0;
	return 1;
}

bool miller(ll n) {
//    ll s, d;
//    s = __builtin_ctzll(n-1);
//    d = (n-1) >> s;
//    return witness_test(s, d, n, 2) && witness_test(s, d, n, 7) && witness_test(s, d, n, 61);
	return prime(n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	int t;
	cin >> t;
	while (t--){
		//cin >> n; n--;
		scanf("%llu",&n); n--;
		while (!prime(n)) n--;
		//cout << n << "\n";
		printf("%llu\n", n);
	}
	
	return 0;
}
