#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+5;
int n, a[maxN*2];
ll l, r, pref[maxN*2];

void solve(){
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n%2==0){
		a[++n] = 0;
		for (int i = 1; i <= n/2; i++) a[n] ^= a[i];
	}
	for (int i = 1; i <= n; i++) pref[i] = pref[i-1]+a[i];
	for (int i = n+1; i <= 2*n; i++){
		a[i] = pref[i/2]&1;
		pref[i] = pref[i-1]+a[i];
	}
	int p = pref[n]&1;
	auto get = [&](ll x){
		int res = 0;
		while (true){
			if (x<=2*n) return res^a[x];
			res ^= p;
			x /= 2;
			if (x%2) return res;
		}
		return res;
	};
	cout << get(l) << "\n";
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

