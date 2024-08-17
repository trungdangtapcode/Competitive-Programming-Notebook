#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], f[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) if (a[i-1]!=1&&a[i]==1) return cout << -1 << "\n", void();
	f[1] = 0;
	int res = 0;
	for (int i = 2; i <= n; i++){
		int x = a[i-1], y = a[i], tmp, d = 0;
		tmp = x;
		while (tmp!=1&&tmp*tmp<=y) tmp *= tmp, d--;
		tmp = y;
		while (tmp!=1&&tmp<x) tmp *= tmp, d++;
		f[i] = max(0ll, f[i-1]+d);
		res += f[i];
	}
	cout << res << "\n"; 
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

