#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e3+5;
int n, a[maxN], k;
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	if (k>2){
		cout << 0 << "\n";
		return;
	}
	if (k==2){
		int res = 1e18;
		for (int i = 1; i <= n; i++){
			for (int j = i+1; j <= n; j++){
				int x = a[j]-a[i];
				int pos = lower_bound(a+1,a+n+1,x)-a;
				if (pos<=n) res = min(res,abs(a[pos]-x));
				if (pos>1) res = min(res,abs(a[pos-1]-x));
				res = min(res,x);
			}
			res = min(res,a[i]);
		}
		cout << res << "\n";
		return;
	}
	if (k==1){
		int res = 1e18;
		for (int i = 1; i <= n; i++){
			for (int j = i+1; j <= n; j++){
				int x = a[j]-a[i];
				res = min(res,x);
			}
			res = min(res,a[i]);
		}
		cout << res << "\n";
		return;
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

