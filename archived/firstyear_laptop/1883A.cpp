#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	cin >> s;
	int res = 0, cur = 1;
	for (int i = 0; i < 4; i++){
//		res += min(abs(s[i]-'1'),10-abs(s[i]-'1');
//		mx = max(mx,s[i]-'0'>0?s[i]-'0':10);
//		mn = min(mn,s[i]-'0');
		int tmp = s[i]-'0'>0?s[i]-'0':10;
		res += abs(tmp-cur)+1;
		cur = tmp;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	
	return 0;
}
