#include <bits/stdc++.h>
using namespace std;
bool validatePinCode(string s){
	if (s.length()!=4&&s.length()!=6) return false;
	for (int i = 0; i < s.length(); i++) if (s[i]<'0'||s[i]>'9') return false;
	return true;
}
int main(){
	string s;
	cin >> s;
	cout << validatePinCode(s);
	return 0;
}
