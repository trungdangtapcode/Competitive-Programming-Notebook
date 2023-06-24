/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int Nmax = 1e5+5;
int n, a[Nmax], suff[Nmax], pref[Nmax];

main(){
    cin >> n;
    suff[n+1] = pref[0] = 1e9;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
        pref[i] = min(pref[i-1],a[i]);
    }
    for (int i = n; i > 0; i--) suff[i] = min(suff[i+1],a[i]);
    int res = 0;
    for (int i = 1; i <= n; i++) res += (pref[i-1]+a[n]>a[i-1]&&suff[i]>a[i-1]);
    cout << res;
    
    return 0;
}
