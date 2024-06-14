#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void solve(){
	cin >> n >> s;
	s = " " + s;
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (i+4<=n&&s.substr(i,5)=="mapie") s[i+2] = '@', res++;
		if (i+2<=n&&s.substr(i,3)=="map") s[i+2] = '@', res++;
		if (i+2<=n&&s.substr(i,3)=="pie") s[i] = '@', res++;
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

