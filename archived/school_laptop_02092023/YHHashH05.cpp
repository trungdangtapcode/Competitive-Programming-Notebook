#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll base = 29;
const ll mod = (1<<31)-1;
const ll maxn = 1e6 + 7; 

ll p[maxn+1], pre[maxn+1], suf[maxn+1];

ll kt(ll len, ll n){
	for(ll i=1;i<=n-len+1;i++){
		ll j = i + len - 1;
		ll ans1 = (pre[j] - pre[i - 1] * p[len] + mod*mod) % mod;
		ll ans2 = (suf[i] - suf[j + 1] * p[len] + mod*mod) % mod; 
//		cout << len << ":	" << ans1 << ' ' << ans2 << "\n";
		if(ans1 == ans2) return 1;
	}
	return 0;
}
main(){
	   std::ios::sync_with_stdio(0);
	   cin.tie(0); cout.tie(0);

		ll n; cin >> n; 
		string s; cin >> s;
		s = "~" + s;
		
		p[0] = 1;
		for(ll i=1;i<=n;i++) p[i] = p[i - 1] * base % mod;
		for(ll i=1;i<=n;i++)	pre[i] = (pre[i - 1] * base + s[i] - 'a' + 1) % mod;
		for(ll i=n;i>=1;i--)	suf[i] = (suf[i + 1] * base + s[i] - 'a' + 1) % mod;

//		for(int i=1;i<=n;i++){
//			kt(i, n); cout << "\n";
//		}

		ll l = 1, r = n, ans = 1;
		while(l <= r){
			ll m = (l + r) / 2;
			if(kt(2*m, n)){
				ans = max(ans,2*m); 
				l = m + 1;
			}
			else r = m - 1;
		}
		l = 1, r = n;
		while(l <= r){
			ll m = (l + r) / 2;
			if(kt(2*m+1, n)){
				ans = max(ans,2*m+1); 
				l = m + 1;
			}
			else r = m - 1;
		}
		cout << ans;
	   return 0;
}

