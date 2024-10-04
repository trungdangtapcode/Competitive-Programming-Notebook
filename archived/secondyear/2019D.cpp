#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], suff[maxN], pref[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int resl = 1, resr = n;
	suff[n+1] = 0;
	pref[0] = 1e9;
	for (int i = 1; i <= n; i++) pref[i] = min(pref[i-1],i+a[i]-1);
	for (int i = n; i >= 1; i--) suff[i] = max(suff[i+1],i-a[i]+1);
	for (int i = 1; i <= n; i++){
		resl = max(resl,i-a[i]+1);
		resr = min(resr,i+a[i]-1);
		if (i+a[i]<=n&&suff[i+a[i]]>i) resr = min(resr,i);
		if (i-a[i]>=1&&pref[i-a[i]]<i) resl = max(resl,i);
		if (i+a[i]<=n&&suff[i+a[i]]>i&&i-a[i]>=1&&pref[i-a[i]]<i) {
			cout << 0 << "\n";
//			exit(0);
			return;
		}
	}
//	cout << resl << ".." << resr << "\n";
	cout << max((int)0,resr-resl+1) << '\n';
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

