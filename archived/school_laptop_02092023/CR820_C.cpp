#include<bits/stdc++.h>

using namespace std;
int n;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> s;
		n = s.length();
		vector<int> cnt[26];
		for (int i = 0; i < n; i++){
			cnt[s[i]-'a'].push_back(i+1);
		} 
		vector<int> res;
		if (s[0]<=s.back()){
			for (int i = s[0]; i <= s.back(); i++){
				for (auto it: cnt[i-'a']) res.push_back(it);
			}
		} else {
			for (int i = s[0]; i >= s.back(); i--){
				for (auto it: cnt[i-'a']) res.push_back(it);
			}
		}
		cout << abs(s[0]-s.back()) << " " << res.size() << "\n";
		for (auto it: res) cout << it << " ";
		cout << "\n";
	}
	
	return 0;
}
