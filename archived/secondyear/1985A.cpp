#include<bits/stdc++.h>

using namespace std;
string s, t;
void solve(){
	cin >> s >> t;
	swap(s[0],t[0]);
	cout << s << " " << t << "\n";
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

