#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, prf[2][26], cnt[2][26];
string s;
void solve(){
	cin >> n >> s;
	s = ' '+ s;
	for (int i = 0; i < 26; i++) cnt[0][i] = cnt[1][i] = 0;
	for (int i = 0; i < 26; i++) prf[0][i] = prf[1][i] = 0;
//	for (int i = 1; )
	if (n%2==0){
		int res1 = 0, res2 = 0;
		for (int i = 1; i <= n; i++){
			cnt[i%2][s[i]-'a']++;
		}
		for (int j = 0; j < 26; j++)
			res1 = max(res1,cnt[0][j]),
			res2 = max(res2,cnt[1][j]);
		cout << n-(res1 + res2) << "\n";
	} else {
		int res = 0;
		for (int i = 1; i <= n; i++){
			cnt[i%2][s[i]-'a']++;
		}
		for (int i = 1; i <= n; i++){
			cnt[i%2][s[i]-'a']--;
			int res1 = 0, res2 = 0;
			for (int j = 0; j < 26; j++) 
				res1 = max(res1,cnt[!(i%2)][j]+prf[i%2][j]),
				res2 = max(res2,cnt[i%2][j]+prf[!(i%2)][j]);
			prf[i%2][s[i]-'a']++;
//			cout << i << " " << res1+res2 << '\n';
			res = max(res,res1+res2);
		}
		cout << n-res << "\n";
	}
//	exit(0);
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

