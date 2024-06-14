//f(i,j,k) = p1*(f(i+1,j,k)+1) + p2*(f(i+1,j-1,k)+1) + p3*(f(i,j+1,k-1)+1) + p0*(f(i,j,k)+1) => f(i,j,k)*(1-p0) = 1 + ... => f(i,j,k) = (1 + ...)/(1-p0)

#include <bits/stdc++.h>

using namespace std;

const int maxN = 3e2+5;
int a[maxN], n, cnt[5];
typedef long double ld;
ld f[maxN][maxN][maxN];
ld calc(int i, int j, int k){
    if (i<0||j<0||k<0) return 0; //
    if (f[i][j][k]!=-1) return f[i][j][k];
    long double p1 = (long double)i/n, p2 = (long double)j/n, p3 = (long double)k/n, p0 = 1-p1-p2-p3;
    f[i][j][k] = (p0 + p1*(calc(i-1,j,k)+1) + p2*(calc(i+1,j-1,k)+1) + p3*(calc(i,j+1,k-1)+1))/(1-p0);
    return f[i][j][k];
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        cnt[a[i]]++;
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k <= n; k++) f[i][j][k] = -1;
    f[0][0][0] = 0;
    cout << fixed << setprecision(9) << calc(cnt[1],cnt[2],cnt[3]);

    return 0;
}


