#include<bits/stdc++.h>

using namespace std;

//https://cp-algorithms.com/algebra/primitive-root.html

const int MOD = 998244353;
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

