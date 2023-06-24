#include<bits/stdc++.h>

using namespace std;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> s;
		cout << s[0]-'0' + s[2] - '0' << "\n";
	}
	
	return 0;
}
