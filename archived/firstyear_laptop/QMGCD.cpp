#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5 + 5, mod = 1e9+7;
int n, a[maxN], cnt[maxN];
int getPow(int a, int b, int mod){
	a %= mod;
	int res = 1;
	while (b){
		if (b&1) res = res*a%mod;
		b /= 2;
		a = a*a%mod;
	}
	return res;
}
main(){
	cin >> n;
	for (int i = 1, x; i <= n; i++){
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= 1e5; i++){
		int cur = 0;
		for (int j = i; j <= 1e5; j+= i) cur += a[j];
		cnt[i] = getPow(2,cur,mod-1)-1;
	}
	for (int i = 1e5; i >= 1; i--){
		for (int j = 2*i; j <= 1e5; j+=i) (cnt[i] -= cnt[j])%=(mod-1);
	}
	for (int i = 1; i <= 1e5; i++){
//		if (i < 10) cout << i << " = "<< cnt[i] << "\n";
		(cnt[i] += mod-1)%(mod-1);
	}
	int res = 1;
	for (int i = 1; i <= 1e5; i++){
		(res *= getPow(i,cnt[i],mod))%= mod;
	}
	cout << res;
	
	return 0;
}
