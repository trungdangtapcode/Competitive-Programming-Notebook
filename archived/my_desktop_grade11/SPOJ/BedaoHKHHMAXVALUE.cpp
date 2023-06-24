#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, q, a[10000005], pref[10000005], suff[10000005];

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k >> x >> q;
	a[1] = x;
	for (int i = 2; i <= n; i++){
		a[i] = 1ll*a[i-1]*k%m;
	}
	for (int i = 1; i <= n; i++){
		a[i] -= q;
	}
	
	pref[0] = suff[n+1] = -1e9;
	for (int i = 1; i <= n; i++){
		pref[i] = max(pref[i-1],a[i]);
	}
	for (int i = n; i >= 1; i--){
		suff[i] = max(suff[i+1],a[i]);
	}
	
	int t, l, r, d;
	cin >> t;
	while (t--){
		cin >> l >> r >> d;
		cout << max(max(pref[l-1],suff[r+1]),pref[n]-d) << '\n';
	}
	
	return 0;
}
