#include<bits/stdc++.h>

using namespace std;

int n;
string s;

void solve(){
	cin >> s;
	n = s.length();
	if (n==2&&s=="()"){
		cout << "NO\n";
		return;
	}
	int tmp = 0;
	for (int i = 0, c = 0; i < n-1; i++) if (s[i]==s[i+1]) tmp = 99;
	cout << "YES\n";
	if (tmp<=1){
		for (int i = 0; i < n; i++) cout << "(";
		for (int i = 0; i < n; i++) cout << ")";
		cout << "\n";
	} else {
		for (int i = 0; i < n; i++) cout << "()";
		cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

