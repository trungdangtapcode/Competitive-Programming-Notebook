#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[200005];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1,a+n+1);
		for (int i = 1; i <= n; i++) a[i] += a[i-1];
		int res = 0;
		for (int i = 1; i <= n; i++){
			res = max(res,abs(abs(a[i])-abs(a[n]-a[i])));
		}
		cout << res << "\n";
	}
	
	return 0;
}
