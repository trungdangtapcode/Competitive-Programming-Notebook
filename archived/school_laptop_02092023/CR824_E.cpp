#include<bits/stdc++.h>

using namespace std;
#define int long long
int fact[3000005], inv[3000005], ans[4], res, n, p;
int nCr(int n, int r){
	return 1ll*fact[n]*inv[r]%p*inv[n-r]%p;
}

main(){
	cin >> n >> p;
	fact[0] = fact[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= 3*n; i++) fact[i] = 1ll*fact[i-1]*i%p;
	for (int i = 2; i <= 3*n; i++) inv[i] = 1ll*inv[p%i]*(p-p/i)%p;
	for (int i = 2; i <= 3*n; i++) inv[i] = 1ll*inv[i-1]*inv[i]%p;
	ans[0] = 1;
	ans[1] = (2ll*fact[2*n]%p-fact[n])%p;
	ans[2] = 2ll*nCr(2*n,n)*fact[2*n]%p*fact[n]%p;
	for (int i = 0; i <= n; i++){
		ans[2] = (ans[2]-1ll*nCr(n,i)*nCr(n,n-i)%p*nCr(2*n-(n-i),n)%p*fact[n]%p*fact[n]%p*fact[n]%p+p)%p;
	}
	ans[1] = ((ans[1]-ans[0])%p+p)%p;
	ans[2] = ((ans[2]-ans[1]-ans[0])%p+p)%p;
	ans[3] = ((fact[3*n]-ans[0]-ans[1]-ans[2])%p+p)%p;
	for (int i = 0; i <= 3; i++) (res += 1ll*ans[i]*i) %= p;
	cout << (res+p)%p;
	return 0;
}
