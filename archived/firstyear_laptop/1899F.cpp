#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, q;
void solve(){
	cin >> n >> q;
	for (int i = 1; i < n; i++){
		cout << i << " " << i+1 << "\n";
	}
	for (int i = 1, last = n-1; i <= q; i++){
		int x; cin >> x;
		if (x==last){
			cout << "-1 -1 -1\n";
			continue;
		}
		cout << n << " " << last << " " << x << "\n";
		last = x;
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
