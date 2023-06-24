#include <bits/stdc++.h>

using namespace std;
map<string,bool> m;
string s;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s, m[s] = true;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s, cout << (m.find(s)!=m.end()?"YES":"NO") << '\n';
	return 0;
}
