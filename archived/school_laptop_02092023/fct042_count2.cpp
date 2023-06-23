#include<bits/stdc++.h>

using namespace std;
int fact[3000005], inv[3000005];
int n, m, res = 0;
const int p = 998244353;
int nCr(int n, int r){
	return 1ll*fact[n]*inv[r]%p*inv[n-r]%p;
}
int main(){
	fact[0] = fact[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= 3e6; i++) fact[i] = 1ll*fact[i-1]*i%p;
	for (int i = 2; i <= 3e6; i++) inv[i] = 1ll*inv[p%i]*(p-p/i)%p;
	for (int i = 2; i <= 3e6; i++) inv[i] = 1ll*inv[i-1]*inv[i]%p;
	
	cin >> n >> m;
	for (int i = 0; i <= min(n,m); i++){
		if ((3*m-i)%2) continue;
		(res += 1ll*nCr(n,i)*nCr((3*m-i)/2+n-1,n-1)%p) %= p; 
	}
//	cout << res << endl;
	for (int i = 0; i <= min(n,m); i++){
		if ((m-i)%2) continue;
		(res -= 1ll*n*nCr(n,i)%p*nCr((m-i)/2+n-1,n-1)%p) %= p;
	}
	for (int i = 0; i <= min(n-1,m); i++){
		if ((m-i)%2) continue;
		(res += 1ll*n*nCr(n-1,i)%p*nCr((m-i)/2+n-2,n-2)%p) %= p;
	}
	cout << (res+p)%p << "\n";
	
	return 0;
}
