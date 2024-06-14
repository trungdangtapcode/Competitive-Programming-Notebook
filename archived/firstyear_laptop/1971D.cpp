#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	cin >> s;
	int c = 0;
	for (int i = 0; i < s.length()-1; i++) c += s[i]!=s[i+1];
	if (s[0]=='0'&&c>0||c>1) c--;
	cout << c+1 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

