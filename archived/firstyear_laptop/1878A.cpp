#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5;
int n, k;
void solve(){
	cin >> n >> k;
	map<int,int> s;
	for (int i = 0; i < n; i++){
		int a; cin >> a;
		s[a] = 1;
	}
	cout << (s.count(k)?"YES":"NO") << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
