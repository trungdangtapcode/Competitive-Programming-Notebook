#include<bits/stdc++.h>

using namespace std;
int n; string s;
void solve(){
	cin >> n;
	cin >> s;
	int res = 0;
	for (char c: s) res += (c=='+'?1:-1);
	cout << abs(res) << "\n"; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
