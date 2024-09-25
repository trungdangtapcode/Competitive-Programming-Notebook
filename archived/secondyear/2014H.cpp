#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
int n, q, a[maxN];
void solve(){
	cin >> n >> q;
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (!mp.count(a[i])) mp[a[i]] = rd();
		a[i] = mp[a[i]];
	}
	for (int i = 1; i <= n; i++) a[i] ^= a[i-1];
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << (a[r]^a[l-1]?"NO\n":"YES\n");
	}
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

