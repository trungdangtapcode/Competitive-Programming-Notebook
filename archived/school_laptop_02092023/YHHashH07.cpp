#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll base = 29;
const ll mod = (1<<31)-1;
const ll maxn = 1e6 + 7; 

ll p[maxn+1], pre[maxn+1], suf[maxn+1];

ll getPre(int i, int j){
	return (pre[j]-pre[i-1]*p[j-i+1]%mod+mod)%mod;
}
ll getSuf(int i, int j){
	return (suf[i]-suf[j+1]*p[j-i+1]%mod+mod)%mod;
}
main(){
	freopen("input.txt","r",stdin);
   std::ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		int n, x; cin >> n >> x; 
		string s; cin >> s;
		s = "~" + s;
		
		p[0] = 1;
		for(ll i=1;i<=n;i++) p[i] = p[i - 1] * base % mod;
		for(ll i=1;i<=n;i++)	pre[i] = (pre[i - 1] * base + s[i] - 'a' + 1) % mod;
		for(ll i=n;i>=1;i--)	suf[i] = (suf[i + 1] * base + s[i] - 'a' + 1) % mod;

//		for(int i=1;i<=n;i++){
//			kt(i, n); cout << "\n";
//		}
		ll res = 0;
		for (int i = 1; i <= n; i++){
			int skip = 0, ans = 0;
			for (int j = 0; j <= x; j++){
				int r = min(i-1,n-i), l = min(skip-1,r), m;
				ans = max(ans,l);
				while(l <= r){
					m = (l + r) / 2;
					if(getPre(i-m,i-skip)==getSuf(i+skip,i+m)){
						ans = max(ans,m);
						l = m + 1;
					}
					else r = m - 1;
				}
				skip = ans+2;
			}
			ans = ans*2 + 1;
			for (;ans>0; ans-=2) res += ans;
		}
		for (int i = 1; i < n; i++){
			int skip = 0, ans = -1;
			for (int j = 0; j <= x; j++){
				int r = min(i-1,n-i-1), l = min(skip-1,r), m;
				ans = max(ans,l);
				while(l <= r){
					m = (l + r) / 2;
					if(getPre(i-m,i-skip)==getSuf(i+1+skip,i+1+m)){
						ans = max(ans,m);
						l = m + 1;
					}
					else r = m - 1;
				}
				skip = ans+2;
			}
			ans = 2*ans+2;
			for (;ans>0; ans-=2) res += ans;
		}
		cout << res << "\n";
	}
	   return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll base = 29;
const ll mod = (1<<31)-1;
const ll maxn = 1e6 + 7; 

ll p[maxn+1], pre[maxn+1], suf[maxn+1];

ll getPre(int i, int j){
	return (pre[j]-pre[i-1]*p[j-i+1]%mod+mod)%mod;
}
ll getSuf(int i, int j){
	return (suf[i]-suf[j+1]*p[j-i+1]%mod+mod)%mod;
}
main(){
   std::ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		int n, x; cin >> n >> x; 
		string s; cin >> s;
		s = "~" + s;
		
		p[0] = 1;
		for(ll i=1;i<=n;i++) p[i] = p[i - 1] * base % mod;
		for(ll i=1;i<=n;i++)	pre[i] = (pre[i - 1] * base + s[i] - 'a' + 1) % mod;
		for(ll i=n;i>=1;i--)	suf[i] = (suf[i + 1] * base + s[i] - 'a' + 1) % mod;

//		for(int i=1;i<=n;i++){
//			kt(i, n); cout << "\n";
//		}
		ll res = 0;
		for (int i = 1; i <= n; i++){
			int skip = 0, ans = 0;
			for (int l = i,  h = i; l >= 1&&h <= n; l--, h++){
			    if (s[l]!=s[h]) skip++;
			    if (skip>x) break;
			    res += h-l+1;
			}
		}
		for (int i = 1; i   < n; i++){
			int skip = 0, ans = 0;
			for (int l = i,  h = i+1; l >= 1&&h <= n; l--, h++){
			    if (s[l]!=s[h]) skip++;
			    if (skip>x) break;
			    res += h-l+1;
			}
		}
		cout << res << "\n";
	}
	   return 0;
}
*/

