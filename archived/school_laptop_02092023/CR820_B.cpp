#include<bits/stdc++.h>

using namespace std;
int n;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		string res;
		for (int i = n-1; i >= 0; i--){
			if (s[i]=='0'){
				res.push_back((char)((s[i-2]-'0')*10+(s[i-1]-'0')-1+'a'));
				i-=2;
			} else {
				res.push_back((char)(s[i]-'0'-1+'a'));
			}
		}
		reverse(res.begin(),res.end());
		cout << res << "\n";
	}
	
	return 0;
}
