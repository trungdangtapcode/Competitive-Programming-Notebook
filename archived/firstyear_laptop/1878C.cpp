#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5;
long long n, k, x;
void solve(){
	cin >> n >> k >> x;
	cout << (k*n-k*(k-1)/2>=x&&k*(k+1)/2<=x?"YES\n":"NO\n"); 
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
