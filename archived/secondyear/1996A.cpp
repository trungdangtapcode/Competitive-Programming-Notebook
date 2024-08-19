#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	cout << (n/4)+(bool)(n%4) << "\n";
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

