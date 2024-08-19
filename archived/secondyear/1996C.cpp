#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, q, pref1[maxN][26], pref2[maxN][26];
string s, t;
void solve(){
	cin >> n >> q >> s >> t;
	s = " " + s;
	t = " " + t;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 26; j++){
			pref1[i][j] = pref1[i-1][j]+(s[i]=='a'+j);
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 26; j++){
			pref2[i][j] = pref2[i-1][j]+(t[i]=='a'+j);
		}
	}
	for (int i = 0; i < q; i++){
		int res = 0;
		int l, r; cin >> l >> r;
		for (int j = 0; j < 26; j++){
			int x = pref1[r][j]-pref1[l-1][j];
			int y = pref2[r][j]-pref2[l-1][j];
			res += abs(x-y);
		}
		cout << res/2 << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

