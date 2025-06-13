#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e3+5;
struct block{
    int x, y, z;
    int get(){
//        cout << x << " " << y << " " << z << "..\n";
        if (x==0) return 1;
        if (y==0) return 2;
        if (z==0) return 3;
    }
    bool operator==(block other){
        return (x==other.x&&y==other.y&&z==other.z);
    }
} a[maxN];
int n, k;
int check(block a, block b){
    if (a.get()==b.get()) return 0;
    int tmp = a.get();
//    cout << tmp << "--\n";
    if (a.x==b.x&&a.x!=0) return (tmp==2?b.y:b.z);
    if (a.y==b.y&&a.y!=0) return (tmp==3?b.z:b.x);
    if (a.z==b.z&&a.z!=0) return (tmp==1?b.x:b.y);
    return 0;
}
main(){
    cin >> n >> k;
    if (n==1){
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= k; i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    int res = 0;
    for (int i = 1; i <= k; i++){
        int cur = n;
        set<int> s;
        for (int j = 1; j < i; j++){
            if (a[i]==a[j]) cur = 0;
            if (check(a[i],a[j])) s.insert(check(a[i],a[j]));
        }
//        for (int x: s) cout << x << " "; cout<< "]\n";
//        cout << i << "." << cur << " " << s.size() << "\n";
//        cout << i << ". " << s.size() << "\n";
        res += min(n-(int)s.size(),cur);
    }
//    cout << check(a[1],a[2]) << "\n";
    cout << res;

    return 0;
}
