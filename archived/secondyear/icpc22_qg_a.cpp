#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    //freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; i++){
            int a; cin >> a;
            mp[a]++;
        }
        long long res = 0;
        long long cnt =0;
        for (auto it: mp){
            int l = it.first;
            res += 1ll*it.second*(it.second-1)*(it.second-2)/6;
            res += 1ll*cnt*it.second*(it.second-1)/2;
            cnt += it.second;
        }
        cout << res << "\n";
    }
    return 0;
}

