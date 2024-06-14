#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], f[maxN], g[maxN], cg[maxN];
void solve(){
	map<int,int> mp;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		f[i] = mp[a[i]];
		mp[a[i]] = 1;
	}
	mp.clear();
	cg[n+1] = 0;
	long long res = 0;
	for (int i = n; i > 0; i--) g[i] = mp[a[i]], mp[a[i]] = 1, cg[i] = cg[i+1] + !g[i];
	for (int i = 1; i <= n; i++){
		if (f[i]) continue;
		res += cg[i];
	}
	cout << res << "\n";
	
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
