#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	cin >> s;
	if (s.length()<=2) return cout << "NO\n", void();
	if (s.substr(0,2)!="10") return cout << "NO\n", void();
	auto t = s.substr(2,s.length()-2);
	if (to_string(stoi(t))==t&&stoi(t)>1) cout << "YES\n";
	else cout << "NO\n";
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

