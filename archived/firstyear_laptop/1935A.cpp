#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	string rs = s;
	reverse(rs.begin(),rs.end());
	cout << (s>rs?rs+s:s) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
