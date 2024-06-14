#include<bits/stdc++.h>

using namespace std;
string s, t;
int n, m;
void solve(){
	cin >> n >> m >> s >> t;
	int res = 0;
	for (int i = 0, j = 0; i < n; i++){
		while (j<m&&t[j]!=s[i]) j++;
		if (j<m) res = i+1;
		j++;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

