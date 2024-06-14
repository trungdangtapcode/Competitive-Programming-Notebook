#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	cin >> s;
	for (int i = 0; i < s.length(); i++) if (s[i]!=s[0]){
		cout << "YES\n";
		swap(s[i],s[0]);
		cout << s << "\n";
		return;
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

