#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, sa, sb, f[15][15];
void solve(){
    cin >> n >> sa >> sb;
    memset(f,0,sizeof(f));
    f[0][0] = 1;
    int res = 0;
    for (int i = 0; i <= sa; i++){
        for (int j = 0; j <= sb; j++){
            if (abs(i-j)>=2&&max(i,j)>=n){
//                res += f[i][j];
                continue;
            };
            f[i][j+1] += f[i][j];
            f[i+1][j] += f[i][j];
        }
    }
    cout << (abs(sa-sb)>=2&&max(sa,sb)>=n?f[sa][sb]:0) << "\n";
}

main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    solve();
    return 0;
}
