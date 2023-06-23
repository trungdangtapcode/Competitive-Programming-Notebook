#include<bits/stdc++.h>

using namespace std;
string s, t, v;
int main(){
	freopen("input.txt","r",stdin);
	cin >> s >> t;
	for (auto c: s) v.push_back(c);
	for (auto c: t) v.push_back(c);
	sort(v.begin(),v.end());
	cout << v.substr(0,s.length());
	
	return 0;
}
