#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	int res = 1e9, even = 0;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		res = min(res,(a+k-1)/k*k-a);
		even += !(a&1);
	}
	if (k==4&&n>1) res = min(res,max(0,2-even));  
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
