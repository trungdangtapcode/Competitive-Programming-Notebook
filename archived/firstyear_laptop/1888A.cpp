//481275
#include<bits/stdc++.h>

using namespace std;

int n, k, c[27];
string s;
void solve(){
	cin >> n >> k >> s;
	memset(c, 0, sizeof(c));
	for (char ch: s) c[ch-'a']++;
	int tmp = 0;
	for (int i = 0; i < 26; i++) c[i]%= 2, tmp += c[i];
	cout << (k>=tmp-(n%2!=k%2)?"YES\n":"NO\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

