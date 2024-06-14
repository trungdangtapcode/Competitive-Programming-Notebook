#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	cin >> s;
	int res = 0;
	for (int i = 0; i < 3; i++){
		if (s[i]-'a'==i) res++;
	}
	if (res) cout << "YES\n"; else cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

