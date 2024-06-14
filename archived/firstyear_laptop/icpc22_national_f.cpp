#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
string s, f, l;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> s >> f >> l;
		cout << (l+f==s?"YES\n":"NO\n");
	}
	return 0;
}
