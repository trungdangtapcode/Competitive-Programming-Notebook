#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int sum = 0;
	int res = 0;
	for (int i = n; i >= 1; i--){
		sum += a[i];
		if (sum>0||i==1) res += sum;
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
