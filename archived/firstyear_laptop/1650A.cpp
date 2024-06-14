#include<bits/stdc++.h>

using namespace std;
string s;
char c;
void solve(){
	cin >> s >> c;
	for (int i = 0; i < s.length(); i++) if (s[i]==c&&i%2==0){
		cout << "YES\n";
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

