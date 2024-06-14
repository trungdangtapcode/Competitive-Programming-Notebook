#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, x, a[maxN];
void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) a[i] += a[i-1];
	int res = 0;
//	for (int d = 0;; d++){
//		int l = 0, h = n, m, ans;
//		while  (l<=h){
//			m = (l+h)/2;
//			if (a[m]+m*d<=x){
//				ans = m;
//				l = m+1;
//			} else h = m-1;
//		}
//		res += ans;
//		if (ans==0) break;
//	}
	for (int i = 1; i <= n; i++) if (x>=a[i]){
		res +=  (x-a[i])/i+1;
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

