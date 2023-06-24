#include <bits/stdc++.h>

using namespace std;
int fac[100005], inFac[100005], inNum[100005], d[100005], n, t, k;
const int p = 1e9+7;
int nCr(int n, int r){
	return (1ll*fac[n]*inFac[n-r]%p*inFac[r]%p);
}

int main(){
	
	fac[0] = fac[1] = inNum[0] = inNum[1] = inFac[0] = inFac[1] = 1;
	for (int i = 2; i <= 1e5; i++) 
		fac[i] = (1ll*fac[i-1]*i)%p, 
		inNum[i] = 1ll*inNum[p%i]*(p-p/i)%p, 
		inFac[i] = (1ll*inFac[i-1]*inNum[i])%p;
	
	cin >> n >> t;
	for (int i = 0, l, r; i < t; i++) cin >> l >> r, d[l]++, d[r+1]--;
	for (int i = 1; i <= n; i++) d[i] += d[i-1], k += (d[i]>0);
	
	long long int res = 0;
	for (int i = 0; i <= k; i++) res = (res+(i%2?-1ll:1ll)*nCr(k,i)*fac[n-i])%p;
	cout << (res+p)%p;
	return 0;
}
