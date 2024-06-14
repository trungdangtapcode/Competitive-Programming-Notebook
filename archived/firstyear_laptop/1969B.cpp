#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	cin >> s;
	int n = s.length();
	s = "0" + s + "0";
	long long res = 0;
	for (int i = n, r = n, l = n; i > 0; i--){
		if (s[i]=='1'){
			res += r-i+(s[i+1]=='0')*(l-i);
			r--;
		} else if (s[i+1]=='1') l = i;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

