#include<bits/stdc++.h>

using namespace std;
int n, m;
string s[105];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		if (i>1&&j>1&&s[i][j]=='1'&&s[i-1][j]=='1'&&s[i][j-1]=='1'&&s[i-1][j-1]=='0'){
			cout << "NO\n";
			return;
		}
		if (i<n&&j<m&&s[i][j]=='1'&&s[i+1][j]=='1'&&s[i][j+1]=='1'&&s[i+1][j+1]=='0'){
			cout << "NO\n";
			return;
		}
		if (i<n&&j>1&&s[i][j]=='1'&&s[i+1][j]=='1'&&s[i][j-1]=='1'&&s[i+1][j-1]=='0'){
			cout << "NO\n";
			return;
		}
		if (i>1&&j<m&&s[i][j]=='1'&&s[i-1][j]=='1'&&s[i][j+1]=='1'&&s[i-1][j+1]=='0'){
			cout << "NO\n";
			return;
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

