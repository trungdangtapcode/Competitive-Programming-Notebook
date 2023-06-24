#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

using namespace std;
#define int long long
int n, k, t, base, mul, seed, res;
int phi(int x){
	int res = x;
	for (int i = 2; i*i <= x; i++) if (x%i==0){
		res -= res/i;
		while (x%i==0) x/= i;
	}
	if (x>1) res -= res/x;
	return res;
}

int getPow(__int128 a, int b, int p){
	__int128 res = 1;
	while (b){
		if (b&1) res = res*a%p;
		a = a*a%p;
		b >>= 1;
	}
	return res;
}

main(){
	cin >> n >> k >> t >> base >> mul >> seed;
	int r = getPow(k,t,phi(base));
	for (int i = 1, a = seed; i <= n; i++){
		a = (a*mul+seed)&((1ll<<20)-1);
		res += getPow(a,r,base);
		if (res>base) res -= base;
	}
	cout << res%base;
	
	
	return 0;
}
