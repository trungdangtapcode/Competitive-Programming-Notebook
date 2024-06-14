#include<bits/stdc++.h>

using namespace std;
int k, n, cnt[26];
string s;
void solve(){
	cin >> n >> k >> s;
	memset(cnt,0,sizeof(cnt));
	for (char c: s) cnt[c-'a']++;
	int ch = 0;
	for (int i = 0; i < 26; i++) ch += (cnt[i]&1);
	cout << (ch<=k+((n-k)&1)?"YES\n":"NO\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
