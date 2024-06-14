#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	int res = -1e18;
	for (int i = 1; i <= n; i++) if (n%i==0){
		int mx = -1e18, mn = 1e18;
		for (int j = 1; j <= n-i+1; j += i){
			mx = max(mx, a[j+i-1]-a[j-1]);
			mn = min(mn, a[j+i-1]-a[j-1]);
		}
		res = max(res,mx-mn);
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
