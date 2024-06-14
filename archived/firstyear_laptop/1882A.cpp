#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	int b = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b++;
		if (b==a[i]) b++;
	}
	cout << b << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
