#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int maxN = 2e5+5;
int n, a[maxN*2];
ll l, r, pref[maxN*2], pref_even[maxN*2];

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
	for (int i = 1; i <= n*2; i++){
		pref_even[i] = pref_even[i-1]+a[i]*(i%2==0);
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
	auto sum = [&](auto&& self, ll m) -> pll { //even, odd
		if (m <= 2*n) return {pref_even[m],pref[m]-pref_even[m]};
		ll even = pref_even[2*n-1], odd = pref[2*n-1]-even;
		if (m%2==0){ //0->1, 2->3
			m++;
			odd -= get(m);
		}
		if (m%4==3){ //3->1
			m++;
			even -= get(m);
			m++;
			odd -= get(m);
		}
		ll e, _;
		tie(e, _) = self(self, m/2);
		e -= pref_even[n];
		ll both = p?(m/2-n+1)-e:e;
		even += both, odd += both;
		return {even,odd};
	};
	auto get_ans = [&](ll x)->ll{
		ll even, odd;
		tie(even, odd) = sum(sum,x);
		return even+odd;
	};
	ll res = get_ans(r)-get_ans(l-1);
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

