#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, sa, sb, f[10][10], cnt[2];
void solve(){
    cin >> n >> sa >> sb;
    int res = 0;
    for (int i = 0; i < (1<<(sa+sb)); i++){
//        cout << bitset<8>(i) << ": \n";
        cnt[0] = cnt[1] = 0;
        int flag = 1;
        for (int j = 0;  j < sa+sb; j++){
            int c = (i>>j)&1;
            cnt[c]++;
            if (abs(cnt[0]-cnt[1])>=2&&max(cnt[0],cnt[1])>=n&&j<sa+sb-1) flag = 0;
        }
        if (cnt[0]!=sa||cnt[1]!=sb) flag = 0;
        if (flag) res++;
//        cout << flag << "\n";
        if (flag) cout << bitset<8>(i) << ": \n";
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
