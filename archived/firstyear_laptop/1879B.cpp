#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 3e5+5;
int n, a[maxN], b[maxN];
void solve(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a,a+n);
	sort(b,b+n);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++){
		sum1 += a[i];
		sum2 += b[i];
	}
	cout << min(sum1+n*b[0],sum2+n*a[0]) << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
