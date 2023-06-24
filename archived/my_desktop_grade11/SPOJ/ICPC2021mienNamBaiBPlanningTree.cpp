#include <bits/stdc++.h>

using namespace std;

int t, n;
long long int fac[10000005], sumFac[10000005], sumSumFac[10000005], p = 1e9 + 7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	fac[0] = sumFac[0] = sumSumFac[0] = 1;
	for (int i = 1; i <= 10000000; i++) fac[i] = fac[i-1]*i%p, sumFac[i] = (sumFac[i-1]+fac[i])%p, sumSumFac[i] = (sumSumFac[i-1]+sumFac[i])%p;
	
	cin >> t;
	while (t--){
		cin >> n;
		cout << (fac[n] - 2*sumFac[n-1] + 1 + sumSumFac[n-2] + p*p)%p << '\n';
	}
	
	
	return 0;
}
