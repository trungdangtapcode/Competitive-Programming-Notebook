#include<bits/stdc++.h>

using namespace std;
int n, cnt[26];
string s;
void solve(){
	int res = -1;
	cin >> s;
	n = s.length();
	memset(cnt,0,sizeof(cnt));
	for (int i = n-1; i >= 0; i--){
		if (cnt[s[i]-'a']==0) res = i;
		cnt[s[i]-'a']++;
	}
	cout << s.substr(res,n-res) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

