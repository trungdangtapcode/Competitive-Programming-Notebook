#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[1000005], n;
main(){
    while (cin >> n){
        if (n==0) break;
        for (int i = 1; i <= n; i++) a[i] = (n/i)*(n/i-1)/2;
        for (int i = n; i >= 1; i--) for (int j = 2*i; j <= n; j+=i) a[i] -= a[j];
        int res = 0;
        for (int i = 1; i<= n; i++) res += a[i]*i;
        cout << res << "\n";
    }

    return 0;
}
//https://onlinegdb.com/cHq5-v-n3
