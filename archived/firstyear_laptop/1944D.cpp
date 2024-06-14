#include<bits/stdc++.h>

using namespace std;

#define int long long
const int maxN = 2e5+5, mod = (1ll<<57)-1, base = 27;
int h[maxN], ih[maxN], p[maxN], prv[maxN];
int getHash(int l, int r){
	return ((h[r]-(__int128)h[l-1]*p[r-l+1])%mod+mod)%mod;
}
int getHashi(int l, int r){
	return ((ih[l]-(__int128)ih[r+1]*p[r-l+1])%mod+mod)%mod;
}
string s;
int n, q;
void solve(){
	cin >> n >> q >> s;
	s = "#" + s;
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = p[i-1]*base%mod;
	h[0] = ih[n+1] = 0;
	for (int i = 1; i <= n; i++) h[i] = (h[i-1]*base + s[i]-'a'+1)%mod;
	for (int i = n; i >= 1; i--) ih[i] = (ih[i+1]*base + s[i]-'a'+1)%mod;
	prv[1] = 1;
	for (int i = 2; i <= n; i++) prv[i] = (s[i]==s[i-1]?prv[i-1]:i);
	while (q--){
		int l, r;
		cin >> l >> r;
		if (prv[r]<=l) cout << 0 << "\n"; //all
		else if (getHash(l,r-2)==getHash(l+2,r)){ //odd
			int len = (r-l+1);
			cout << len*(len+1)/2 - ((len+1)/2)*((len+1)/2) << "\n";
		} else {
			int len = (r-l+1);
			cout << len*(len+1)/2 -1- len*(getHash(l,r)==getHashi(l,r)) << "\n";
		}
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

