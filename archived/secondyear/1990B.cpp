#include<bits/stdc++.h>

using namespace std;
int n, x, y;
void solve(){
	cin >> n >> x >> y;
	int s[] = {1,-1};
	for (int i = 1, e=-s[y%2]; i < y; i++, e*=-1) cout << e << " ";
	for (int i = y; i <= x; i++) cout << 1 << " ";
	for (int i = x+1, e=-1; i <= n; i++, e*=-1) cout << e << " ";
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

