#include<bits/stdc++.h>
using namespace std;

const int N =2e5 +5;

int a[N];
int n, mi, mx;

void solve(){
    cin >> n >> mi >> mx;
    for(int i=1;i<=n;i++){
        char c; cin >> c;
        a[i] = c - '0';
    }

    int pos = -1;
    for(int i=1;i<=n;i++) if(a[i] == 0){
        pos = i; break;
    }
    if(pos == -1) return cout << "YES\n", void();

    while(pos + mi - 1 <= n){
        for(int i=pos;i<=pos+mi-1;i++) a[i] = 1 - a[i];
        //for(int i=1;i<=n;i++) cout << a[i]; cout <<"\n";
        int ok = 1;
        for(int i=1;i<=n;i++){
            if(a[i] == 0){
                ok = 0;
                pos = i;
                break;
            }
        }
        if(ok) return cout << "YES\n", void();
    }
    pos = -1;
    for(int i=n;i>=1;i--){
        if(a[i] == 0){
            pos = i; break;
        }
    }
    if(pos == -1) return cout << "YES\n", void();

    while(mi < mx && pos - mi >= 1){
        for(int i=pos-mi;i<pos;i++){
            a[i] = 1 - a[i];
        }
        for(int i=pos-mi;i<=pos;i++){
            a[i] = 1 - a[i];
        }
        //for(int i=1;i<=n;i++) cout << a[i]; cout <<"\n";

        int ok = 1;
        for(int i=n;i>=1;i--){
            if(a[i] == 0){
                ok = 0;
                pos = i;
                break;
            }
        }
        if(ok) return cout << "YES\n", void();
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}

