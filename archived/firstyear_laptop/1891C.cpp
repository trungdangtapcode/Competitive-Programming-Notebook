#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int a[maxN], n;
void solve(){
	cin >> n;
	for (int i = 1; i<= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += a[i];
	}
	int mx = 0, pref = 0;
	for (int i = 1, preff = 0; i <= n; i++){
		if (preff*2<=sum) mx = i, pref += a[i];
		preff += a[i];
	}
//	cout << pref << " " << sum << " " << mx << "\n";
	int res = 0;
	for (int i = n; i > mx; i--){
//		cout << a[i] << " -> ";
		if (pref>=a[i]){
			pref -= a[i];
			res += a[i] + 1;
		} else {
			res += (a[i]-pref+1)/2 + (a[i]>1);
			pref = 0; //
		}
//		cout << res << " r = " << pref << "\n";
	};
	res += (pref+1)/2 + (pref>1);
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	solve();
	return 0;
}
