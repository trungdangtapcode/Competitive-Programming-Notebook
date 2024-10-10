#include<bits/stdc++.h>

using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
bool MillerRabin(u64 n, int iter=15) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
int countDivisors(int n) {
    int count = 0;
    int sqrt_n = sqrt(n);  // Calculate square root of n for efficient looping

    for (int i = 1; i <= sqrt_n; i++) {
        if (n % i == 0) {
            // If i divides n, then both i and (n / i) are divisors
            if (i == n / i) {
                // If divisors are the same, count only once
                count++;
            } else {
                // Count both i and (n / i)
                count += 2;
            }
        }
    }
    
    return count;
}

#define int long long
const int lim = 1e6;
int n, a, b, c;
bool p[lim+5];

bool isprime(int n) {
    return MillerRabin(n,35);
}
bool isprime2(int n){
	int x = sqrt(n);
	if (x*x!=n) return 0;
	return isprime(x);
}
int g(int x){
	int res = 1;
	for (int prime = 2; prime<=lim&&prime*prime*prime<=x; prime++){
		int cnt = 1;
//		cout << prime << "\n";
		while (x%prime==0) x/=prime, ++cnt;
		res *= cnt;
	}
//	cout << res << " " << x << "\n";
	if (isprime(x)) res *= 2;
	else if (isprime2(x)) res *= 3;
	else if (x!=1) res *= 4;
	return res;
}
long long solve(long long N,long long q)
{ 
    if(q == -1)
        return 0;
    if(N%q != 0)
        return 0;

    long long n = N/q;
    long long res = 0;
    for(long long i = 1;i*i <= n;i++)
        if(n%i == 0) {
            if(i*i == n)
                res++;
            else
                res += 2;
        }
    return res;
}
int f(int x, int y){
//	return solve(x,y);
	if (x%y) return 0;
	int t = x/y;
	return g(t);
//	return countDivisors(t);
}
void solve(){
//	cout << g(12) << "\n";
//	return;
//	for (int i = 1; i <= 1000000; i++){
//		int x = countDivisors(i), y = g(i);
//		cout << x << " " << y << " " << i << "\n";
//		assert(x==y);
//	}
//	cout << "ok!";
//	return;
	cin >> n >> a >> b >> c;
	for (int i = 2; i <= lim; ++i) p[i] = 1;
	for (int i = 2; i*i <= lim; ++i) if (p[i]){
		for (int j = i*i; j <= lim; j += i) p[j] = 0;
	}
//	cout << g(100) << "\n";
//	return;
	int g, flag = 0;
	g = __gcd(a,b);
	if (a/g>n/b) flag = 1;
	int l = a/g*b;
	g = __gcd(l,c);
	if (l/g>n/c) flag = 1;
	l = l/g*c;
	int divabc = (flag?0:f(n,l));
	g = __gcd(a,b);
	int divab = (a/g>n/b?0:f(n,a/g*b));
	g = __gcd(c,b);
	int divbc = (b/g>n/c?0:f(n,b/g*c));
	g = __gcd(a,c);
	int divac = (a/g>n/c?0:f(n,a/g*c));
	cout << divab+divac+divbc-2*divabc << "\n";
}

int32_t main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

