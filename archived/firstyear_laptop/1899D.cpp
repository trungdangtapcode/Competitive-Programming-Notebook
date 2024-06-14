#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int res = 0;
	map<ii,int> mp;
	for (int i = 1; i <= n; i++){
		int x = a[i], y = a[i];
		while (y%2==0) y/=2, x--;
		res += mp[{x,y}];
		mp[{x,y}]++;
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
