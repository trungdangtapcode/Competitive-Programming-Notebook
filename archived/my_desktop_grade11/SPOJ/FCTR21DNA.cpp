#include <bits/stdc++.h>

using namespace std;
string s, s0;
int n;
bool check(string s, string s0){
	if (s.length()!=s0.length()) return false;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) if (s[i]!=s0[i]) cnt++;
	return (cnt<=2);
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> s >> n;
	for (int i = 0; i < n; i++){
		cin >> s0;
		if (check(s,s0)) cout << i+1 << '\n';
	}
	
	return 0;
}
