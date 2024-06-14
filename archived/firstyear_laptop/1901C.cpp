#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int res = 0;
	vector<int> vec;
	while (true){
		int mx = -1e18, mn = 1e18, x;
		for (int i = 1; i <= n; i++){
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		if (mx==mn){
			break;
		}
		if (mn%2==1){
			x = 1;
		} else x = 0;
		vec.push_back(x);
		for (int i = 1; i <= n; i++){
			a[i] = (a[i]+x)/2;
		}
		res++;
	}
	cout << res << "\n";
	if (res<=n){
		for (int i: vec) cout << i << " "; cout << "\n";
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
