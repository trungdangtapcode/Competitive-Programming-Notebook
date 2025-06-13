#include<bits/stdc++.h>

using namespace std;
#define int long long

int n, k;
map<int,int> mp;
int gett(int k){
    if (k==1) return 0;
    if (mp.count(k)) return mp[k];
    int &res = mp[k];
    res = 1e9;
    for (int i = 2; i <= 9; i++) if (k%i==0) res = min(res,gett(k/i)+1);
    return res;
}

main(){

    cin >> n >> k;
    if (gett(n)>k){
        cout << -1;
        return 0;
    }
//    cout << gett(n) << "\n";
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= 9; j++) if (n%j==0){
            if (i+gett(n/j)>k) continue;
            cout << j << "";
            n /= j;
            break;
        }
    }
//    cout << n;


    return 0;
}
