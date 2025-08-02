#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

long long val[4 * MAXN];
long long lazy[4 * MAXN];
bool hasLazy[4 * MAXN];

long long power(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long modInverse(long long a, long long mod) {
    return power(a, mod - 2, mod);
}

void buildTree(int k, int l, int r, vector<long long>& arr) {
    if (l == r) {
        val[k] = arr[l];
        lazy[k] = 0;
        hasLazy[k] = false;
        return;
    }
    int m = (l + r) / 2;
    buildTree(2 * k, l, m, arr);
    buildTree(2 * k + 1, m + 1, r, arr);
    val[k] = (val[2 * k] + val[2 * k + 1]) % MOD;
    lazy[k] = 0;
    hasLazy[k] = false;
}

void downTree(int k, int l, int r) {
    if (!hasLazy[k]) return;
    
    int m = (l + r) / 2;
    // Set left child
    val[2 * k] = (lazy[k] * (m - l + 1)) % MOD;
    lazy[2 * k] = lazy[k];
    hasLazy[2 * k] = true;
    
    // Set right child
    val[2 * k + 1] = (lazy[k] * (r - m)) % MOD;
    lazy[2 * k + 1] = lazy[k];
    hasLazy[2 * k + 1] = true;
    
    hasLazy[k] = false;
}

void updateTree(int k, int l, int r, int u, int v, long long x) {
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
        val[k] = (x * (r - l + 1)) % MOD;
        lazy[k] = x;
        hasLazy[k] = true;
        return;
    }
    downTree(k, l, r);
    
    int m = (l + r) / 2;
    updateTree(2 * k, l, m, u, v, x);
    updateTree(2 * k + 1, m + 1, r, u, v, x);
    val[k] = (val[2 * k] + val[2 * k + 1]) % MOD;
}

long long getTree(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return val[k];
    downTree(k, l, r);
    
    int m = (l + r) / 2;
    return (getTree(2 * k, l, m, u, v) + getTree(2 * k + 1, m + 1, r, u, v)) % MOD;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    buildTree(1, 1, N, A);
    
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        
        // Get total stones in range [L, R]
        long long total = getTree(1, 1, N, L, R);
        
        // Calculate stones per plate
        long long length = R - L + 1;
        long long perPlate = (total * modInverse(length, MOD)) % MOD;
        
        // Set each plate in range to perPlate
        updateTree(1, 1, N, L, R, perPlate);
    }
    
    // Output results
    for (int i = 1; i <= N; i++) {
        long long result = getTree(1, 1, N, i, i);
        cout << result;
        if (i < N) cout << " ";
    }
    cout << "\n";
    
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();

    return 0;
}
