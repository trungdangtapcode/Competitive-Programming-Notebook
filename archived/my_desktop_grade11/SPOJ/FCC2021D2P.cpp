#include <bits/stdc++.h>

using namespace std;
int n, k;
long long int fac[400005], inFac[400005], inNum[400005], inPower2[400005];
const long long int p = 1e9+7;

long long int nCr(int n, int r){
	if (r<0||r>n) return 0;
	return (fac[n]*inFac[n-r]%p*inFac[r]%p);
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	fac[0] = inFac[0] = inNum[0] = fac[1] = inFac[1] = inNum[1] =  1; 
	for (int i = 2; i <= 4e5; i++)
		fac[i] = (fac[i-1]*i)%p,
		inNum[i] = inNum[p%i]*(p-p/i)%p,
		inFac[i] = (inFac[i-1]*inNum[i])%p;
	inPower2[0] = 1;
	for (int i = 1; i <= 4e5; i++)
		inPower2[i] = (inPower2[i-1]*inNum[2])%p;
	
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		cout << fac[2*n]*inFac[n]%p*inPower2[n]%p*nCr(n,k)%p << '\n';
	}
	
	return 0;
}
