#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[200005];
main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	int res = 1e18;
	for (int i = 1; i <= n; i++) res = min(res,abs(2*a[i]-a[n]));
	cout << res;
	
	return 0;
}
