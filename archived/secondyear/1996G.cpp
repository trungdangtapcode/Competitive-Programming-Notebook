#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, d[maxN];

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) d[i] = 0;
	for (int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		int tmp = rng();
		d[u] ^= tmp, d[v] ^= tmp;
	}
	int s = 0;
	map<int,int> mp;
	int res = 0;
	for (int i = 1;i <= n; i++){
		s ^= d[i];
		mp[s]++;
		res = max(res,mp[s]);
	}
	cout << n-res << "\n";
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
//https://pastebin.pl/view/f83e6d9a
