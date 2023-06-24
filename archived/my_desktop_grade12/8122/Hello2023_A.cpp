#include<bits/stdc++.h>

using namespace std;
string s;
int n;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		int res = -1;
		for (int i = 0; i < s.length()-1; i++){
			if (s[i]=='R'&&s[i+1]=='L'){
				res = 0;
				break;
			}
			if (s[i]=='L'&&s[i+1]=='R'){
				res = i+1;
				break;				
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}
