#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, m, a[maxN], b[maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		cin >> b[i];
		b[i] += b[i-1];
	}
	int mmin = 1e18;
	for (int i = 1; i <= m; i++){
		mmin = min(mmin,0+a[i]-b[i]);
	}
	for (int i = m+1; i <= n; i++){
		int f = mmin+b[i-1];
		mmin = min(mmin,f+a[i]-b[i]);
	}
	cout << mmin+b[n] << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

