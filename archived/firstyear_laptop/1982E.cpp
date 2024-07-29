#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9+7, inv2 = (mod-mod/2)%mod;
int n, k;
typedef pair<int,int> ii;
map<ii,int> mp;
int f(int n, int k){
	if (k<0||n<1) return 0;
	if (mp.count({n,k})) return mp[{n,k}];
	int b = 63-__builtin_clzll(n);
	if (b<=k){
		n %= mod;
		return mp[{n,k}] = n*(n+1)%mod*inv2%mod;
	}
	return mp[{n,k}] = (f((1ll<<b)-1,k)+f(n-(1ll<<b),k-1))%mod;
}


void solve(){
	cin >> n >> k;
	cout << f(n,k) << "\n";
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

