#include<bits/stdc++.h>

using namespace std;
const int maxN = 55;
int n, m;
string s[maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	for (int j = 1; j <= m; j++){
		for (int i = 1, cnt = 0; i <= n; i++){
			cnt += s[i][j]=='*';
			if (s[i][j]=='*') s[i][j] = '.';
			if (i==n||s[i+1][j]=='o'){
				for (int k = i; k >= i-cnt+1; k--) s[k][j] = '*';
				cnt = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		cout << s[i].substr(1,m) << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

