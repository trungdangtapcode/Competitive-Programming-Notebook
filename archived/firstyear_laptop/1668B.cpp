#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, m, a[maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	int pos = 0;
	for (int i = 2; i <= n; i++) pos += a[i]+1;
	pos += a[n];
	cout << (pos<m?"YES\n":"NO\n");
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

