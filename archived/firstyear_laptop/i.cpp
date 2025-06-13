#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e3+5, mod = 1e9+7;
int f[maxN][2*maxN], g[maxN][2*maxN], a[maxN], n;
int getpow(int a, int n){
    int res = 1;
    a %= mod;
    while (n){
        if (n%2) res = 1ll*res*a%mod;
        n /= 2;
        a = 1ll*a*a%mod;
    }
    return res;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    f[0][0] = 1;
    int res = 0;
    for (int i = 1; i <= n; i++){
//        if (i>=3) cout << i << " " << a[i] << " = " << g[i-1][a[i]] << "\n";
        if (i>=3) (res += getpow(2,i-1)-g[i-1][a[i]] )%=mod;
        for (int j = 0; j <= 10000; j++){
            f[i][j] = f[i-1][j];
            if (j>=a[i]) (f[i][j] += f[i-1][j-a[i]])%= mod;
            if (j) g[i][j] = (f[i][j]+g[i][j-1])%mod;
            else g[i][j] = f[i][j];
//            cout << f[i][j] << " ";

        }
//        cout << "f\n";
//        for (int j = 0; j <= 10; j++) cout << g[i][j] << " ";
//        cout << "g\n";
    }
    cout << (res+mod)%mod << "\n";

    return 0;
}
