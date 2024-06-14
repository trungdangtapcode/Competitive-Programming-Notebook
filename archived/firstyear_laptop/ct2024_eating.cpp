#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], pref[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1]+a[i];
	}
	int mmax = 0;
	for (int i = 1; i <= n; i++){
		if (pref[n]-pref[i]+1<a[i]) break;
		mmax = i;
	}
	int mmin = (int)(2e5);
	mmin *= (int)(1e13);
	for (int i = n; i > mmax; i--){
		mmin = min(mmin,pref[i-1]-a[i]+1);
//		cout << mmin << "\n";
	}
	for (int i = mmax; i >= 1; i--){
		mmin = min(mmin,pref[i-1]-a[i]+1);
		if (pref[i-1]<=mmin){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

