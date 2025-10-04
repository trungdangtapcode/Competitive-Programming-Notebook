#include<bits/stdc++.h>
using namespace std;

const int maxN = 200005;
long long val[maxN];
int cnt[maxN];
int len;

void updt(int x, long long v, int c) {
    for (; x <= len; x += x & -x) {
        if (v > val[x] || (v == val[x] && c > cnt[x])) {
            val[x] = v;
            cnt[x] = c;
        }
    }
}

pair<long long, int> gett(int x) {
    long long res_val = 0;
    int res_cnt = 0;
    for (; x; x -= x & -x) {
        if (val[x] > res_val || (val[x] == res_val && cnt[x] > res_cnt)) {
            res_val = val[x];
            res_cnt = cnt[x];
        }
    }
    return {res_val, res_cnt};
}

void solve(){
    int n;
    cin >> n;
    
    vector<long long> h(n), v(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    
    // compression number -> discrete
    vector<long long> sorted_h = h;
    sort(sorted_h.begin(), sorted_h.end());
    sorted_h.erase(unique(sorted_h.begin(), sorted_h.end()), sorted_h.end());
    
    map<long long, int> compress;
    for (int i = 0; i < (int)sorted_h.size(); i++) {
        compress[sorted_h[i]] = i + 1;
    }
    
    len = sorted_h.size();
    
    for (int i = 0; i <= len; i++) {
        val[i] = 0;
        cnt[i] = 0;
    }
    
    long long max_value = 0;
    int max_count = 0;
    
    for (int i = 0; i < n; i++) {
        int compressed_h = compress[h[i]];
        pair<long long, int> best = gett(compressed_h - 1);
        
        long long new_val = best.first + v[i];
        int new_cnt = best.second + 1;
        
        updt(compressed_h, new_val, new_cnt);
        
        if (new_val > max_value || (new_val == max_value && new_cnt > max_count)) {
            max_value = new_val;
            max_count = new_cnt;
        }
    }
    
    cout << max_value << " " << max_count << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef JESSIE
    freopen("input.txt","r",stdin);
    #endif
//    int t; cin >> t;
//    while (t--)
        solve();
}
