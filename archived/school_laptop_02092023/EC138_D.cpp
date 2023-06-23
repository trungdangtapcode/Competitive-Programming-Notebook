#include<bits/stdc++.h>

using namespace std;
int n;
long long int m, base[300005], res, fact[300005];
bool p[300005];
const long long int mod = 998244353;
int main(){
	cin >> n >> m;
	base[0] = 1;
	for (int i = 1; i <= n; i++) base[i] = base[i-1]*(m%mod)%mod;
	for (int i = 2; i <= n; i++) res = (res+base[i])%mod;
	for (int i = 2; i <= n; i++) p[i] = 1;
	for (int i = 2; i*i <= n; i++) if (p[i]) for (int j = i*i; j <= n; j+=i) p[j] = 0;
	fact[0] = 1;
	for (int i = 1; i <= n; i++){
		if (p[i]) fact[i] = fact[i-1]*i;
		else fact[i] = fact[i-1];
		if (fact[i]>m){
			for (int j = i; j <= n; j++) fact[j] = m+1;
			break;
		}
	}
	long long int t = (m/fact[1])%mod;
	for (int i = 2; i <= n; i++){
		t *= (m/fact[i])%mod;
		t %= mod;
		res -= t;
		res %= mod;
	}
	cout << (res%mod+mod)%mod;
	
	return 0;
}
