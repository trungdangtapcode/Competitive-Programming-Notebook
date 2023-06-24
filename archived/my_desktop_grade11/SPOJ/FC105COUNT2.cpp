#include <bits/stdc++.h>

using namespace std;
int n, m;
int x, y, z, res, fac[3000005], inFac[3000005], inNum[3000005], p = 998244353;
//1ll*[product]%p -> int
int nCr(int n, int r){
	if (r<0||r>n) return 0;
	return (1ll*fac[n]*inFac[n-r]%p*inFac[r]%p);
}
long long int calc(int n, int x, int y){ //n so = x (y so le)
	long long int res = 0;
	for (int i = x%2; i <= min({n,x,y}); i += 2){
		res = (res+1ll*nCr((x-i)/2+n-1,n-1)*nCr(n,i)%p)%p;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	fac[0] = fac[1] = inFac[0] = inFac[1] = inNum[0] = inNum[1] = 1;
	for (int i = 2; i <= 3e6; i++)
		fac[i] = (1ll*fac[i-1]*i)%p,
		inNum[i] = 1ll*inNum[p%i]*(p-p/i)%p,
		inFac[i] = (1ll*inFac[i-1]*inNum[i])%p;
		
	cin >> n >> m;
	x = calc(n,3*m,m); //(1)(3)
	y = calc(n,m,m); //p0 >= 2m
	z = calc(n-1,m,m); //p0 = 2m
	res = (x-1ll*(y-z)*n%p+p)%p;
	cout << res;
	
	return 0;
}
