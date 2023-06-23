#include<bits/stdc++.h>

using namespace std;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (cin >> s){
		cout << (char)toupper(s[0]) << s.substr(1,s.length()-1);
	}
	
	return 0;
}
