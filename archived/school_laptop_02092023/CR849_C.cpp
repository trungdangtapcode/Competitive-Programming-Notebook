#include<bits/stdc++.h>

using namespace std;
int n;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		int res = n;
		for (int i = 0, j = n-1; i < j; i++, j--){
			if (s[i]==s[j]) break;
			res -= 2;
		}
		cout << res << "\n";
	}
	
	
	return 0;
}
