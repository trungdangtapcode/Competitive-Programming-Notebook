#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, c;
long long a[200005];
typedef pair<int,int> ii;
ii b[200005];
void solve(){
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> a[i];
	long long x = a[1];
	for (int i = 2; i<= n; i++) b[i].first = c*i-a[i], b[i].second = i;
	sort(b+2,b+n+1);
	for (int i = 2; i <= n; i++){
		if (x<b[i].first) return cout <<"No\n", void();
		x += a[b[i].second];
	}
	cout << "Yes\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
