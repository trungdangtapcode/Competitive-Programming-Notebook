#include<bits/stdc++.h>

using namespace std;
string s;
int mp[26], cnt[200005][3];
void solve(){
    cin >> s;
    int n = s.length();
    s = " " + s;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 3; j++) cnt[i][j] = cnt[i-1][j];
        cnt[i][mp[s[i]-'A']]++;
//        for (int j = 0; j < 3; j++) cout << cnt[i][j] << " "; cout << "\n";
    }
    int mx = -1e9, res = -1;
    for (int i = 2; i <= n; i++){
        int cur = 0;
        for (int j = 1; j <= n; j += i){
            int jj = min(n,j+i-1);
            int tmp = max({cnt[jj][0]-cnt[j-1][0],cnt[jj][1]-cnt[j-1][1],cnt[jj][2]-cnt[j-1][2]});
            cur += tmp;
//            cout << j << "->" << jj << " = " << tmp << "\n";
        }
//        cout << i << ": " <<cur << "\n";
        if (cur>=mx){
            mx = cur;
            res = i;
        }
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    mp['R'-'A'] = 0;
    mp['P'-'A'] = 1;
    mp['S'-'A'] = 2;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
