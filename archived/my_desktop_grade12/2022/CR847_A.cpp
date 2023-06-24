#include<bits/stdc++.h>

using namespace std;

string spi = "314159265358979323846264338327";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		string s;
		cin >> s;
		int res = -1;
		for (int i = 0; i < s.length(); i++){
			if (s[i]!=spi[i]) break;
			res = i;
		}
		cout << res + 1 << "\n";
	}
}
