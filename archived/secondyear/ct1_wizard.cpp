#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 8e5 + 5;
long long a[maxN], b[maxN];
int n, m;

void push(int v, int l, int r) {
    if (l != r && (a[v] || b[v])) {
        a[v*2] += a[v];
        b[v*2] += b[v];
        a[v*2+1] += a[v];
        b[v*2+1] += b[v];
        a[v] = b[v] = 0;
    }
}

void upd(int ql, int qr, long long x, long long y, int v = 1, int l = 1, int r = -1) {
    if (r == -1) r = n;
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        a[v] += x;
        b[v] += y;
        return;
    }
    push(v, l, r);
    int mid = (l + r) / 2;
    upd(ql, qr, x, y, v*2, l, mid);
    upd(ql, qr, x, y, v*2+1, mid+1, r);
}

long long qry(int p, int v = 1, int l = 1, int r = -1) {
    if (r == -1) r = n;
    if (l == r) return a[v] + b[v] * p;
    push(v, l, r);
    int mid = (l + r) / 2;
    if (p <= mid) return qry(p, v*2, l, mid);
    return qry(p, v*2+1, mid+1, r);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k, l, r;
        cin >> k >> l >> r;
        if (k == 0) upd(l, r, 1, 0);
        else if (k == 1) upd(l, r, -1, 0);
        else if (k == 2) upd(l, r, 1 - l, 1);
        else upd(l, r, l - 1, -1);
    }
    
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << qry(i);
    }
    cout << "\n";
    
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef JESSIE
    freopen("input.txt","r",stdin);
    #endif
    solve();
}
