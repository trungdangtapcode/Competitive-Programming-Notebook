#include<bits/stdc++.h>

using namespace std;
#define int long long
int fact[1000005], invf[1000005], x, y;
const int p =1e18+7;
int nCr(int n, int r){
	return fact[n]*invf[r]%p*invf[n-r]%p;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fact[0] = fact[1] = invf[0] = invf[1] = 1;
	for (int i = 2; i <= 1e6; i++) fact[i] = fact[i-1]*i%p;
	for (int i = 2; i <= 1e6; i++) invf[i] = invf[p%i]*(p-p/i)%p;
	for (int i = 2; i <= 1e6; i++) invf[i] = invf[i-1]*invf[i]%p;
	
	int t; cin >> t;
	while (t--){
		cin >> x >> y;
//		if (x&1&&y&1){
//			cout << 0 << "\n";
//			continue;
//		}
//		cout << nCr((x+y)/2,x/2)*fact[x]%p*fact[y]%p << "\n";
		int ans = max(x*(x-1)*(x-2),0ll) + max(y*(y-1)*(y-2),0ll) + max(x*y*(y-1),0ll) + max(y*x*(x-1),0ll);
		cout << ans << "\n";
	}
	
	return 0;
}
