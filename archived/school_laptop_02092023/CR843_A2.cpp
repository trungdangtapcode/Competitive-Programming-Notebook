#include<bits/stdc++.h>

using namespace std;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> s;
		if (*max_element(s.begin(),s.end())==*min_element(s.begin(),s.end())){
			cout << s[0] << " " << s[1] << " " << s.substr(2,s.length()-2) << "\n";
			continue;
		};
		if (s[0]=='a'){
			int p = s.find('b');
			if (p==s.length()-1) {
				cout << s.substr(0,s.length()-2) << " " << s[s.length()-2] << " " << s[s.length()-1] << "\n";
				continue;
			}
			cout << s.substr(0,p) << " " << s.substr(p,s.length()-p-1) << " " << s.back() << "\n";
		} else {
			int p = s.find('a');
			if (p==s.length()-1) {
				cout << s[0] << " " << s.substr(1,s.length()-2) << " " << s[s.length()-1] << "\n";
				continue;
			}
			cout << s.substr(0,p) << " " << s[p] << " " << s.substr(p+1,s.length()-p-1) << "\n";
		}
	}
	return 0;
}
