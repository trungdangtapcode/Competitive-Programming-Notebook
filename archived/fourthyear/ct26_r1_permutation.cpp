#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+5, MOD = 1e9+7;
int a[N], n;
void solve(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int res = 1;
	for (int i = 0; i < n; i++){
		res = (1ll*res*max(min(n, a[i])-i,0))%MOD;
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

