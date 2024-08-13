#include<bits/stdc++.h>

using namespace std;
int n, k, m;
void solve(){
	cin >> n >> m >> k;
	for (int i = n; i >= k; i--) cout << i << " ";
	for (int i = m+1; i < k; i++) cout << i << " ";
	for (int i = 1; i <= m; i++) cout << i << " ";
	cout << "\n";
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

