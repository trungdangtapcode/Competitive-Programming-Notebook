#include<bits/stdc++.h>
using namespace std;
void solve(){
    int g, w, r, n;
    cin >> g >> w >> r >> n;
    int s = (g+w+r);
    n %= s;
    if (n<g){
        cout << "Guiding Beat\n";
        return;
    }
    n -= g;
    if (n<w){
        cout << "Warning Beat\n";
        return;
    }
    n -= w;
    if (n<r){
        cout << "Resting Phase\n";
        return;
    }
    while (true);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    //freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

