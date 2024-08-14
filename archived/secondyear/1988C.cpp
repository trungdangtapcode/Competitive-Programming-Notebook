#include<bits/stdc++.h>

using namespace std;
long long n;
void solve(){
	cin >> n;
	if (__builtin_popcountll(n)==1){
		cout << "1\n" << n << "\n";
		return;
	}
	cout << __builtin_popcountll(n)+1 << "\n";
	for (int i = 60; i >= 0; i--){
		if ((n>>i&1)==0) continue;
		cout << (n^(1ll<<i)) << " ";
	}
	cout << n << "\n";
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

