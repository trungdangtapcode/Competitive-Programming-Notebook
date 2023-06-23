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
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int unsigned long long
bool p[4000005];
int sz, n;
vector<int> v; 
gp_hash_table<int,bool> mp;

using u64 = uint64_t;
using u128 = __uint128_t;

int binpower(int base, int e, int mod) {
    int result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(int n, int a, int d, int s) {
    int x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(int n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    int d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

bool isPrime(int x){
	for (int i = 2; i*i <= x; i++) if (x%i==0) return 0;
	return 1;
}

bool check2(int x){
	int a = 0, b = 0;
	for (int i = sqrt(x); i >= 2; i--) if (isPrime(i)){
		a = i;
		break;
	}
	for (int i = sqrt(x)+1; ; i++) if (isPrime(i)){
		b = i;
		break;
	}
	return (a*b==x);
}

main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	
	for (int i = 2; i <= 4e6; i++) p[i] = 1;
	for (int i = 2; i*i <= 4e6; i++) if (p[i]) for (int j = i*i; j <= 4e6; j += i) p[j] = 0;
	for (int i = 2; i <= 4e6; i++) if (p[i]) v.push_back(i);
	sz = v.size();
	v.push_back(1e9);
	for (int i = 0; i < sz-2; i++){
		for (int j = i, p = 1; v[j] <= ULLONG_MAX/p;){
			p *= v[j++];
			mp[p] = 1;
		}
	}
	
//	cin >> n;
	int t; cin >> t;
	while (t--){
		int n = (1ll<<53)-1;
		cin >> n;
		if (MillerRabin(n)){
			cout << "NICE\n";
			continue;
		}
		if (check2(n)){
			cout << "NICE\n";
			continue;
		}
		if (mp[n]){
			cout << "NICE\n";
			continue;
		}
		cout << "UGLY\n";
	}
	
	
	return 0;
}
