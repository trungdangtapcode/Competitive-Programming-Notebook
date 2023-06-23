#include<bits/stdc++.h>

using namespace std;
string s = "codeforces";
char c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> c;
		cout << (s.find(c)!=string::npos?"YES\n":"NO\n");
	}
	
	return 0;
}
