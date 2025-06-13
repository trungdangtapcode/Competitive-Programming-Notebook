#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, a[maxN], f[maxN], g[maxN];
int pl = 1, pr = 1, cura[maxN], cur = 0, lazy[maxN*4], val[maxN*4];
void reset(){
    for (int i = 1; i <= 4*n; i++) val[i] = 0, lazy[i] = 0;
    pr = pl = 1;
    cur = 0;
}
void down(int k){
    if (lazy[k]==0) return;
    lazy[2*k] += lazy[k];
    lazy[2*k+1] += lazy[k];
    val[2*k] += lazy[k];
    val[2*k+1] += lazy[k];
    lazy[k] = 0;
    //val[2*k] += lazy[k];
    //val[2*k+1] += lazy[k];
}
void updt(int k, int l, int r, int u, int v, int x){
    if (l>v||r<u) return;
    if (u<=l&&r<=v){
        val[k] += x;
        lazy[k] += x;
        return;
    }
    down(k);
    int m = (l+r)/2;
    updt(2*k,l,m,u,v,x);
    updt(2*k+1,m+1,r,u,v,x);
    val[k] = min(val[2*k],val[2*k+1]);
}
int gett(int k, int l, int r, int u, int v){
    if (l>v||r<u) return 1e9;
    if (u<=l&&r<=v){
        return val[k];
    }
    down(k);
    int m = (l+r)/2;
    return min(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}

void pushh(int x){
//    cout << "push " << pr << " " << a[pr] << "\n";
    updt(1,1,n,pr,pr,x-cur-1);
//    if (pr>pl) updt(1,1,n,pl,pr-1,-1);
    pr++;
    cur++;
}
void popp(){
    updt(1,1,n,pl,pl,1e9);
    pl++;
    if (pr>pl) updt(1,1,n,pl,pr-1,1);
    cur--;
}
int top(){
    if (pl>=pr) return 1e9;
    return gett(1,1, n, pl, pr-1);
}


main(){
    cin >> n;
    reset();
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pushh(a[i]);
//        cout << top() << "\n";
//        for (int i = 1; i <= n; i++) cout << gett(1,1, n, i, i) << " ";
//        cout << "\n";
        while (top()<0) popp();
        f[i] = cur;
//        cout << top() << " " << cur << "\n";
//        int tmp = val[1];
//        if (tmp>0){
//            cur++;
//            pushh(a[i]);
//        } else {
//            while (val[1]<=0) popp();
//        }
    }
    reset();
    int res= 0;
    for (int i = n; i > 0; i--){
        pushh(a[i]);
        while (top()<0) popp();
        g[i] = cur;
//        cout << i << " " << a[i] << ". " << f[i] << " " << g[i] << "\n";
        res = max(res,min(f[i],g[i]));
    }
    cout << res;


    return 0;
}
