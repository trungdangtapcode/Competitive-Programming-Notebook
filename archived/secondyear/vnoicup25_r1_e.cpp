#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 1 << 20;
const int g = 3; // primitive root for 998244353

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

vector<long long> fact(MAXN + 1), ifact(MAXN + 1);

void init_fact() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    ifact[MAXN] = power(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--) {
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    }
}

void ntt(vector<long long>& a, bool invert) {
    int n = a.size();
    
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    
    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = invert ? power(g, MOD - 1 - (MOD - 1) / len) : power(g, (MOD - 1) / len);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long long u = a[i + j], v = a[i + j + len / 2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = w * wlen % MOD;
            }
        }
    }
    
    if (invert) {
        long long n_inv = power(n, MOD - 2);
        for (long long& x : a) {
            x = x * n_inv % MOD;
        }
    }
}

vector<long long> multiply(vector<long long> const& a, vector<long long> const& b) {
    vector<long long> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    
    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; i++) {
        fa[i] = fa[i] * fb[i] % MOD;
    }
    ntt(fa, true);
    
    vector<long long> result(a.size() + b.size() - 1);
    for (int i = 0; i < result.size(); i++) {
        result[i] = fa[i];
    }
    return result;
}

//vector<long long> compute_s_fast(int n, vector<long long>& fact, vector<long long>& ifact) {
//	vector<long long> s(n + 1, 0);
//    
//    // For each a, we need to compute:
//    // s[a] = a! * S(k=0 to a-1) [(n-a+k)! / k!]
//    
//    // We can rewrite this as a convolution problem
//    // Let f[k] = (n-k)! and g[k] = 1/k!
//    // Then s[a] = a! * S(k=0 to a-1) f[a-k] * g[k]
//    
//    vector<long long> f(n + 1), g(n + 1);
//    
//    // Prepare sequences for convolution
//    for (int k = 0; k <= n; k++) {
//        f[k] = fact[n - k];  // (n-k)!
//        g[k] = ifact[k];     // 1/k!
//    }
//    
//    // Compute convolution
//    vector<long long> conv = multiply(f, g);
//    
//    // Extract results
//    for (int a = 1; a <= n; a++) {
//        long long sum = 0;
//        for (int k = 0; k < a; k++) {
//            sum = (sum + conv[a - 1 - k]) % MOD;
//        }
//        s[a] = fact[a] * sum % MOD;
//    }
//    
//    return s;
//}

vector<long long> compute_s_fast(int n, vector<long long>& fact, vector<long long>& ifact) {
    vector<long long> s(n + 1, 0);
    
    // Original: s[a] = S(j=1 to a) [a! * ifact[a-j] * fact[n-j]]
    // Rewrite: s[a] = a! * S(j=1 to a) [ifact[a-j] * fact[n-j]]
    // Substitute k = j-1: s[a] = a! * S(k=0 to a-1) [ifact[a-1-k] * fact[n-1-k]]
    
    // This is convolution of:
    // f[i] = ifact[i] (for i from 0 to n-1)
    // g[i] = fact[n-1-i] (for i from 0 to n-1)
    
    vector<long long> f(n), g(n);
    
    for (int i = 0; i < n; i++) {
        f[i] = ifact[i];           // 1/i!
        g[i] = fact[n - 1 - i];    // (n-1-i)!
    }
    
    // Compute convolution
    vector<long long> conv = multiply(f, g);
    
    // Extract results
    for (int a = 1; a <= n; a++) {
        if (a - 1 < conv.size()) {
            s[a] = fact[a] * conv[a - 1] % MOD;
        }
    }
    
    return s;
}
// The simplest O(n) solution using prefix sums
//vector<long long> compute_s_optimal(int n, vector<long long>& fact, vector<long long>& ifact) {
//    vector<long long> s(n + 1, 0);
//    
//    // Your original: s[a] = S(j=1 to a) [a! * ifact[a-j] * fact[n-j]]
//    // Rewrite as: s[a] = a! * S(j=1 to a) [ifact[a-j] * fact[n-j]]
//    
//    // Key insight: we can build this incrementally
//    // Define helper[i] = ifact[i] * fact[n-i] for i from 0 to n
//    vector<long long> helper(n + 1);
//    for (int i = 0; i <= n; i++) {
//        helper[i] = ifact[i] * fact[n - i] % MOD;
//    }
//    
//    // Now s[a] = a! * S(j=1 to a) helper[a-j]
//    // Which is s[a] = a! * S(k=0 to a-1) helper[k] where k = a-j
//    
//    long long running_sum = 0;
//    for (int a = 1; a <= n; a++) {
//        running_sum = (running_sum + helper[a - 1]) % MOD;
//        s[a] = fact[a] * running_sum % MOD;
//    }
//    
//    return s;
//}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
    init_fact();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int max_mask = 1 << k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> freq(max_mask, 0);
        for (int x : a) {
            freq[x]++;
        }

        vector<long long> U(max_mask, 0);
        for (int x = 0; x < max_mask; x++) {
            if (freq[x] == 0) continue;
            for (int m = x; m > 0; m = (m - 1) & x) {
                U[m] = (U[m] + freq[x]) % MOD;
            }
        }

        // Precompute s_n(a) for a = 0 to n
//        vector<long long> s(n + 1, 0);
//        for (int a = 1; a <= n; a++) {
//            long long sum = 0;
//            long long a_fact = fact[a];
//            for (int j = 1; j <= a; j++) {
//                long long term = a_fact * ifact[a - j] % MOD * fact[n - j] % MOD;
//                sum = (sum + term) % MOD;
//            }
//            s[a] = sum;
//        }
		vector<long long> s;
		s = compute_s_fast(n, fact, ifact);

        long long ans = 0;
        for (int m = 1; m < max_mask; m++) {
            if (U[m] == 0) continue;
            int pop = __builtin_popcount(m);
            long long sign = (pop % 2 == 0) ? MOD - 1 : 1;
            ans = (ans + sign * s[U[m]] % MOD) % MOD;
        }
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }
    return 0;
}
