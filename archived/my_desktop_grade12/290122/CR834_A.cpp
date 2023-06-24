#include<bits/stdc++.h>

using namespace std;
map<char,char> mp;
string s;
int main(){
	mp['Y'] = 'e';
	mp['e'] = 's';
	mp['s'] = 'Y';
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> s;
		bool res = true;
		if (mp[s[0]]==0) res = false;
		for (int i = 1; i < s.length(); i++){
			if (mp[s[i-1]]!=s[i]) res = false;
		}
		cout << (res?"YES\n":"NO\n");
	}
	
	return 0;
}
