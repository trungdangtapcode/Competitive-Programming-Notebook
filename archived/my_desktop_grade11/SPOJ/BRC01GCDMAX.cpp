#include <bits/stdc++.h>

using namespace std;
long long int a[1000005], gcdL[1000005], gcdR[1000005];
int main(){
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	gcdL[0] = 0;
	for (int i = 1; i <= n; i++) gcdL[i] = __gcd(gcdL[i-1],a[i]);
	gcdR[n+1] = 0;
	for (int i = n; i >= 1; i--) gcdR[i] = __gcd(gcdR[i+1],a[i]);
	
	long long int res = 0;
	for (int i = 1; i <= n; i++){
		res = max(res,__gcd(gcdL[i-1],gcdR[i+1]));
	}
	if (n==1) cout << 1000000000; else cout << res;
	
	return 0;
}
