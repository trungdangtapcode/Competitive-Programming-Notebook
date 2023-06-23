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
		int x = 0, y = 0, res = 0;
		for (char c: s){
			if (c=='U') y++;
			else if (c=='D') y--;
			else if (c=='R') x++;
			else x--;
			if (x==1&&y==1) res = 1;
		}
		cout << (res?"YES\n":"NO\n");
	}
	
	
	return 0;
}
