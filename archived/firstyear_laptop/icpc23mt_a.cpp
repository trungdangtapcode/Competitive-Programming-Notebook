#include<bits/stdc++.h>

using namespace std;
long long a, b, c;
void solve(){
    cin >> a >> b >> c;
    if (c==0) cout << "NO CURVE\n";
    else if (c>0) cout << "CURVE UP\n";
    else cout << "CURVE DOWN\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
