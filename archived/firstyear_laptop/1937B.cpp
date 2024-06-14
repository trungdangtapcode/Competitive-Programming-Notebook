#include<bits/stdc++.h>

using namespace std;
int n;
string s[3];
void solve(){
	cin >> n;
	cin >> s[1] >> s[2];
	s[1] = " " + s[1];
	s[2] = " " + s[2];
	int f = 1;
	string res;
	for (int i = n-1, c = 1; i >= 1; i--){
		if (s[1][i+1]==s[2][i]){
			if (c) f++;
		} else if (s[1][i+1]<s[2][i]){
			c = 0;
		} else {
			f = 1;
			c = 1;
		}
	}
	cout << s[1][1];
	for (int i = 1, c = 1; i < n; i++){
		if (c==1){
			if (s[1][i+1]<=s[2][i]){
				cout << s[1][i+1];
			} else {
				c = 2;
				cout << s[2][i];
			}
		} else cout << s[2][i];
	}
	cout << s[2][n] << "\n";
	cout << f << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

