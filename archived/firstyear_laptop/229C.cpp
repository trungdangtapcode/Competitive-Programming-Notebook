#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;
int n, m, d[maxN];

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		d[u]++;
		d[v]++;		
	}
	long long res = 0;
	for (int i = 1; i <= n; i++){
		res += 1ll*(n-1)*(n-2)-3ll*d[i]*(n-1-d[i]);
	}
	cout << res/6 << "\n";
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

