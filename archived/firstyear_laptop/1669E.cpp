#include<bits/stdc++.h>

using namespace std;
int cnt[11*11], n;
void solve(){
	cin >> n;
	memset(cnt,0,sizeof(cnt));
	long long res = 0;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		for (int c = 0; c < 11; c++) if (c!=s[0]-'a') res += cnt[c*11+s[1]-'a'];
		for (int c = 0; c < 11; c++) if (c!=s[1]-'a') res += cnt[(s[0]-'a')*11+c];
		cnt[(s[0]-'a')*11+s[1]-'a']++;
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

