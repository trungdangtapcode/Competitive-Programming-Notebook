#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	cout << k*(n-1)+1 << "\n";
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

