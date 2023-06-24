#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	int sum = 0, k;
	
	cin >> s >> k;
	for (int i = 0; i < s.length(); i++){
		sum += s[i] - '0';
	}
	if ((k==3&&(s[s.length()-1]-'0')%2==0&&sum%3==0)||
		(k==2&&(s[s.length()-1]-'0')%2==0)||
		k==1) cout << "YES\n"; else cout << "NO\n";
}
int main(){
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
