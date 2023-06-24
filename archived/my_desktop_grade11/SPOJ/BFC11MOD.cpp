#include <bits/stdc++.h>

using namespace std;
int n; string s;
int main(){
	cin >> n;
	n = abs(n)+1e9;
	s = to_string(n);
	cout << s.substr(s.length()-3,3);
	return 0;
}
