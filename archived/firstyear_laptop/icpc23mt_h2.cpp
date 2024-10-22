#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], q;
int to[maxN*45][2], ntrie = 0, cnt[maxN*45];
long long val[maxN*45];
struct Trie{
    int root;
    Trie(){
        root = ++ntrie;
    }
    void del(int x){
        int u = root;
        cnt[u]--;
        for (int i = 19; i >= 0; i--){
            int c = (x>>i)&1;
            if (to[u][c]==0) to[u][c] = ++ntrie;
            u = to[u][c];
            cnt[u]--;
        }
    }
    void add(int x, long long v){
        int u = root;
        val[u] += v;
        cnt[u] += (v>0?1:-1);
        for (int i = 19; i >= 0; i--){
            int c = (x>>i)&1;
            if (to[u][c]==0) to[u][c] = ++ntrie;
            u = to[u][c];
            val[u] += v;
            cnt[u] += (v>0?1:-1);
        }
    }
    long long query(int x){
        int u = root;
        long long res = 0;
        for (int i = 19; i >= 0; i--){
            int c = (x>>i)&1;
            if (c&&to[u][!c]!=0) res += val[to[u][!c]];
            if (to[u][c]==0) return res;
            u = to[u][c];
        }
        return res;
    }
    long long gett(int l, int r){
        return query(r+1)-query(l);
    }
    long long query2(int x){
        int u = root;
        long long res = 0;
        for (int i = 19; i >= 0; i--){
            int tmp = (to[u][0]?cnt[to[u][0]]:0);
//            cout << (tmp) << " " << x << "\n";
            if (tmp>=x){
                if (to[u][0]==0) return res;
                u = to[u][0];
            } else {
                x -= tmp;
                res += (to[u][0]?val[to[u][0]]:0);;
                if (to[u][1]==0) return res;
                u = to[u][1];
            }
        }
        return res;
    }
} tree[maxN], cc;

void solve(){
//    cc.add(1,1);
//    cc.add(2,4);
//    cc.add(2,-4);
//    cc.add(3,9);
//    cc.add(5,25);
//    cout << cc.query2(5) << "\n";
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        tree[a[i]].add(i,1ll*i*i);
    }
    long long last = 0;
    while (q--){
        int t; cin >> t;
        if (t==1){
            int p; cin >> p;
            int i = (p + last -1) % (n-1) + 1;
            tree[a[i]].add(i,-1ll*i*i);
            tree[a[i+1]].add(i+1,-1ll*(i+1)*(i+1));
            tree[a[i+1]].add(i,1ll*i*i);
            tree[a[i]].add(i+1,1ll*(i+1)*(i+1));
            swap(a[i],a[i+1]);
        } else if (t==2){
            int l, r, x;
            cin >> l >> r >> x;
            l = (l+last-1)%n+1;
            r = (r+last-1)%n+1;
            x = (x+last-1)%n+1;
            if (l>r) swap(l,r);
            last = tree[x].gett(l,r);
            cout << last << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
//            cout << last << "---\n";
            l = (l+last-1)%n+1;
            r = (r+last-1)%n+1;
            x = (x+last-1)%n+1;
            if (l>r) swap(l,r);
            last = tree[x].query2(r+1)-tree[x].query2(l);
            cout << last << "\n";
        }
    }
}

main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int t; cin >> t;
//    while (t--)
    solve();
    return 0;
}
