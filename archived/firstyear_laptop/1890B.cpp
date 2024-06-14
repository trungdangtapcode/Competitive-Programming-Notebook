#include<bits/stdc++.h>

using namespace std;
int n, m;
string s, t;
void solve(){
	cin >> n >> m;
	cin >> s >> t;
	bool check = 0;
	for (int i = 1; i < m; i++){
		if (t[i]==t[i-1]) check = 1; 
	}
	for (int i = 1; i < n; i++){
		if (s[i]==s[i-1]){
			if (check) return cout << "No\n", void();
			if (s[i-1]==t[0]||s[i]==t[m-1]) return cout << "No\n", void();
		}
	}
	cout << "Yes\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
