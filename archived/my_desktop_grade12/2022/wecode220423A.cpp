#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[200005];
main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i];
	int q = sum/n, r = sum%n, res =0;
	for (int i = 1; i <= n; i++){
		res += abs(q + (i>=n-r+1) - a[i]);
	}
	cout << res/2;
	
	
	
	return 0;
}
