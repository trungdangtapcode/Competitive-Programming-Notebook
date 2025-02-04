#include<bits/stdc++.h>

using namespace std;

void solve(){
	set<int > s1, s2;
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> x;
		s1.insert(x);
	}
	for (int i = 1; i <= n; i++){
		cin >> x;
		s2.insert(x);
	}
	cout << (s1.size()+s2.size()>3?"YES\n":"NO\n");
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

