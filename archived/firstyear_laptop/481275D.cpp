#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, m, a[maxN], b[maxN], f[maxN];

void solve(){
	cin >> n >> m;
	for (int i = 2; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(a+2,a+n+1);
	sort(b+1,b+n+1);
	int res = n;
	for (int i = 1; i <= n; i++) f[i] = 0;
	for (int i = 2, j = 1; i <= n; i++){
		while (j<=n&&a[i]>=b[j]) j++;
		if (j<=n) f[j++] = 1, res--;
	}
	int mx = -1;
	for (int i = 1; i <= n; i++){
		if (!f[i]) mx = b[i]-1; 
	}
	cout << res*m - min(m,mx) << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
