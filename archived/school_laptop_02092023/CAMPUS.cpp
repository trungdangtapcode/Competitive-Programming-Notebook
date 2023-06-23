#include<bits/stdc++.h>

using namespace std;
string s[105];
int n, m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	s[0].assign(m+2,'L');
	s[n+1].assign(m+2,'L');
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = "L" + s[i] + "L";
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j]=='F'&&(i+j)%2) s[i][j] = 'B';
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j]=='F'&&s[i+1][j]!='B'&&s[i][j+1]!='B'&&s[i-1][j]!='B'&&s[i][j-1]!='B') s[i][j] = 'B';
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cout << s[i][j];
		cout << "\n";
	}
	
	return 0;
}
