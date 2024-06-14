#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	string s;
	cin >> s;
	int res = 0;
	set<char> st;
	for (int i = 0; i < n; i++){
		st.insert(s[i]);
		res += st.size();
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}
