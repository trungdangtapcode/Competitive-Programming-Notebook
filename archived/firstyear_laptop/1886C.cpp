#include<bits/stdc++.h>

using namespace std;
#define int long long
string s;
const int maxN = 1e6+5;
int n, k, prv[maxN], nxt[maxN];
void solve(){
	cin >> s >> k;
	n = s.length();
	s = "@" + s + "@";
	for (int i = 0; i <= n; i++){
		prv[i] = i-1;
		nxt[i] = i+1;
	}
	int cnt;
	for (cnt = 0; cnt < n; cnt++){
		if (k>n-cnt){
			k -= n-cnt;
		} else {
			break;
		}
	}
	int pos = 1;
//	cout << cnt << " " << k << "\n";
	while (cnt){
//		cout << pos << "s\n";
		if (s[pos]>s[nxt[pos]]){
//			cout << "del\n";
			cnt--;
			int tmp = prv[pos];
			prv[nxt[pos]] = tmp;
			nxt[tmp] = nxt[pos];
			pos = prv[pos];
		} else pos = nxt[pos];
	}
	pos = 0;
	while (k--){
		pos = nxt[pos];
	}
	cout << s[pos] << "";
//	for (int i = 0; i <= n; i++) cout << nxt[i] << " ";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) 
	solve();
	
	return 0;
}
