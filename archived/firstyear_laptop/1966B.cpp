#include<bits/stdc++.h>

using namespace std;
int n, m;
string s[505];
void solve(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	bool a[4] = {0}, b[4] = {0};
	for (int i = 0; i < n; i++) if (s[i][0]=='W') a[0] = 1; else b[0] = 1;
	for (int i = 0; i < n; i++) if (s[i][m-1]=='W') a[1] = 1; else b[1] = 1;
	for (int i = 0; i < m; i++) if (s[0][i]=='W') a[2] = 1; else b[2] = 1;
	for (int i = 0; i < m; i++) if (s[n-1][i]=='W') a[3] = 1; else b[3] = 1;
	cout << ((a[0]&&a[1]&&a[2]&&a[3]||b[0]&&b[1]&&b[2]&&b[3])?"YES\n":"NO\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

