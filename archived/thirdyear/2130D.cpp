#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e4+5;
int n, a[maxN], b[maxN];
int fen[maxN];

void update(int idx, int val) {
    for (; idx <= 2 * n; idx += idx & -idx) {
        fen[idx] += val;
    }
}

long long query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += fen[idx];
    }
    return sum;
}

long long cntInv(int arr[], int size) {
    vector<int> values(arr, arr + size);
    sort(values.begin(), values.end());
    auto last = unique(values.begin(), values.end());
    values.erase(last, values.end());
    
    unordered_map<int, int> rank;
    for (int i = 0; i < values.size(); i++) {
        rank[values[i]] = i + 1; 
    }
    
//    memset(fen, 0, sizeof(fenwick));
    for (int i = 0; i <= 2*n; i++) fen[i] = 0;
    
    long long ivc = 0;
    for (int i = size - 1; i >= 0; i--) {
        int mapped = rank[arr[i]];
        ivc += query(mapped - 1); 
        update(mapped, 1); 
    }
    
    return ivc;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                cnt1++;
            }
        }
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) cnt2++;
        }
        if (cnt1 > cnt2) {
            b[i] = 2 * n - a[i];
        } else {
            b[i] = a[i];
        }
    }
    cout << cntInv(b, n) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef JESSIE
    freopen("input.txt","r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
