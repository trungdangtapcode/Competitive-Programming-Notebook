#include<bits/stdc++.h>

using namespace std;
const int maxN = (1<<18)+5;
int n, cnt[50], k, c, a[maxN], bad[maxN];
string s;
void solve(){
	cin >> n >> c >> k >> s;
	for (int i = 0; i < c; i++) cnt[i] = 0;
	for (int i = 0; i < (1<<c); i++) bad[i] = 0;
	for (int i = 1; i <= n; i++) a[i] = s[i-1]-'A';
	for (int i = 1, cur_mask = 0; i <= n; i++){
		if (!cnt[a[i]]) cur_mask ^= 1<<a[i];
		cnt[a[i]]++;
		if (i<k) continue;
		bad[cur_mask] = 1;
		cnt[a[i-k+1]]--;
		if (!cnt[a[i-k+1]]) cur_mask ^= 1<<a[i-k+1];
	}
	bad[1<<a[n]] = 1;
	int res = 1e9;
	for (int mask = 0; mask < (1<<c); mask++){
		if (!bad[mask]){
			res = min(res,c-__builtin_popcount(mask));
			continue;
		}
		for (int i = 0; i < c; i++) bad[mask|(1<<i)] |= 1;
	}
	cout << res << "\n";
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

