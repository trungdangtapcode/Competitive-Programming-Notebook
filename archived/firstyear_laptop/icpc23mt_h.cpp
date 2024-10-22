#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace pb_ds;
const int maxN = 2e5+5;
int n, a[maxN], q;
unordered_map<int,long long> val[maxN*4];
unordered_map<int,int> val2[maxN*4];
void updt(int k, int l, int r, int u, int v, long long x, int y){
    if (l>u||r<u) return;
    if (l==r){
        val[k][v] += x;
        val2[k][v] += y;
        if (val[k][v]==0) val[k].erase(v);
        if (val2[k][v]==0) val2[k].erase(v);
        return;
    }
    int m = (l+r)/2;
    updt(2*k,l,m,u,v,x,y);
    updt(2*k+1,m+1,r,u,v,x,y);
    val[k][v] += x;
    val2[k][v] += y;
    if (val[k][v]==0) val[k].erase(v);
    if (val2[k][v]==0) val2[k].erase(v);
}
long long gett(int k, int l, int r, int u, int v, int x){
    if (l>v||r<u) return 0;
    if (u<=l&&r<=v){
        if (val[k].count(x)) return val[k][x];
        return 0;
    }
    int m =(l+r)/2;
    return gett(2*k,l,m,u,v,x) + gett(2*k+1,m+1,r,u,v,x);
}
//int gett2(int k, int l, int r, int u, int v, int x){
//    if (l>v||r<u) return 0;
//    if (u<=l&&r<=v){
//        if (val2[k].count(x)) return val2[k][x];
//        return 0;
//    }
//    int m =(l+r)/2;
//    return gett(2*k,l,m,u,v,x) + gett(2*k+1,m+1,r,u,v,x);
//}
long long findd(int k, int l, int r, int u, int x){
//    cout << l << ".." << r << " " << x << "\n";
    int tmpk = (val2[k].count(x)?val2[k][x]:0);
    if (x==0) return 0;
    if (tmpk==u) return (val[k].count(x)?val[k][x]:0);
    int m = (l+r)/2;
    int tmp = (val2[2*k].count(x)?val2[2*k][x]:0);
//    for (auto it: val2[2*k]) cout << it.first << "," << it.second << "\n";
//    cout << tmp << "\n";
    if (tmp>=u){
        return findd(2*k,l,m,u,x);
    } else {
        long long tmp2 = (val[2*k].count(x)?val[2*k][x]:0);
        return tmp2 + findd(2*k+1,m+1,r,u-tmp,x);
    }
    return findd(2*k,l,m,u,x) + findd(2*k+1,m+1,r,u,x);
}

void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        updt(1, 1, n, i, a[i], 1ll*i*i,1);
    }
    long long last = 0;
    while (q--){
        int t; cin >> t;
        if (t==1){
            int p; cin >> p;
            int i = (p + last -1) % (n-1) + 1;
            updt(1,1,n,i,a[i], -1ll*i*i, -1);
            updt(1,1,n,i+1,a[i+1], -1ll*(i+1)*(i+1), -1);
            updt(1,1,n,i,a[i+1], 1ll*i*i, 1);
            updt(1,1,n,i+1,a[i], 1ll*(i+1)*(i+1), 1);
            swap(a[i],a[i+1]);
        } else if (t==2){
            int l, r, x;
            cin >> l >> r >> x;
            l = (l+last-1)%n+1;
            r = (r+last-1)%n+1;
            x = (x+last-1)%n+1;
            if (l>r) swap(l,r);
            last = gett(1,1,n,l,r,x);
            cout << last << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
//            cout << last << "---\n";
            l = (l+last-1)%n+1;
            r = (r+last-1)%n+1;
            x = (x+last-1)%n+1;
            if (l>r) swap(l,r);
//            cout << l << " " << r << " " << x << "\n";
//            cout << findd(1,1,n,r,x) << "-" << findd(1,1,n,l-1,x) << "\n"'
            last = findd(1,1,n,r,x)-findd(1,1,n,l-1,x);
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
