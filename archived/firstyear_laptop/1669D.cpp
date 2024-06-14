#include<bits/stdc++.h>

using namespace std;
string s;
int n;
void solve(){
	cin >> n >> s;
	s ="W"+ s + "W";
	char ch = 'W';
	for (int i = 1, flag = 0; i <= n+1; i++){
		if (s[i]=='W'){
			if (s[i-1]!='W'&&flag==0){
				cout << "NO\n";
				return;
			}
		} else {
			if (s[i-1]=='W') ch = s[i], flag = 0;
			if (s[i]!=ch) flag = 1;
		}
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

