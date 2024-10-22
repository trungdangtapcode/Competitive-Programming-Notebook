#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long res = 0;
    map<int,int> s;
    for (int i = 1, j = 0; i <= n; i++){
        while (j<n&&!s[a[j+1]]) s[a[++j]] = 1;
//        for (int x: s) cout << x << " "; cout << "\n";
//        for (auto it: s) if (it.second) cout << it.first << " "; cout << "\n";
//        cout << s[1] << "\n";
//        cout << *s.find(2) << "\n";
//        cout << i << ".." << j << "\n";
        res += j-i+1;
        s[a[i]] = 0;
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    solve();
    return 0;
}
