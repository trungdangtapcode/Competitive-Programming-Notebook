#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 3e5+5;
int n, a[maxN], pref[maxN];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) a[i] -= 2*i, pref[i] = pref[i-1] + a[i];
	map<int,int> mp;
	int res = 0;
	mp[0]=1;
	for (int i = 1; i <= n; i++) res += mp[pref[i]]++;
	cout << res;
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

