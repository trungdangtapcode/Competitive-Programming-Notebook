#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;
	int n = s.length();
	stack<long long int> sta;
	for (int i = 0; i < n; i++){
		if (s[i]=='(') sta.push(-1);
		else if (s[i]==')') {
			long long int x = 0;
			while (sta.top()!=-1){
				x += sta.top();
				sta.pop();
			}
			sta.pop();
			sta.push(x);
		}
		else if (s[i]<='9'&&s[i]>='0') {
			long long int x = sta.top();
			sta.pop();
			sta.push(x*(s[i]-'0'));
		} else {
			if (s[i]=='C') sta.push(12);
			if (s[i]=='H') sta.push(1);
			if (s[i]=='O') sta.push(16);
		}
	}
	long long int res = 0;
	while (!sta.empty()) res += sta.top(), sta.pop();
	cout << res << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		solve();
	}

	
	return 0;
}
