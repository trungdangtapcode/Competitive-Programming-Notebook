#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 3e5+5;
int n, a[maxN], s[maxN], pref[maxN], ss[maxN];

int g(int x){
	//n + n-1 + n-2 + ...
	return n*x-x*(x-1)/2;
}
int f(int x){
	int l = 1, r = n, m, res = 0;
	while (l<=r){
		m = (l+r)>>1;
		if (g(m)<=x){
			l = m+1;
			res = m;
		} else r = m-1;
	}
	int ans = pref[res];
	if (g(res)<x){
		int y = x-g(res), cur = res+1;
		int bonus = ss[cur+y-1]-ss[cur-1]-y*s[cur-1];
		return ans+bonus;
	}
	return ans;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
	for (int i = 1; i <= n; i++) ss[i] = ss[i-1]+s[i];
	for (int i = 1; i <= n; i++) pref[i] = pref[i-1]+ss[n]-ss[i-1]-(n-i+1)*s[i-1];
	int q; cin >> q;
//	f(6);
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << f(r)-f(l-1) << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

