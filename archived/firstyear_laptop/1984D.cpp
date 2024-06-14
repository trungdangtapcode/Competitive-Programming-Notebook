#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 3e5+5, mod = 1e9+9, base = 31;
int n, hash1[maxN];
string s;
void solve(){
	cin >> n >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++){
		hash1[i] = (hash1[i-1]*base + s[i]-'a'+1)%mod; 
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

