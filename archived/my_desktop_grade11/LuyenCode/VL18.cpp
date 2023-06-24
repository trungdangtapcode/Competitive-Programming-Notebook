#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin >> s;
	while (s.size()>1&&s.back()=='0') s.pop_back();
	reverse(s.begin(),s.end());
	cout << s;
	
	return 0;
}
