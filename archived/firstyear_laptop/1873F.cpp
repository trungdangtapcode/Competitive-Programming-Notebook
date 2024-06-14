#include<bits/stdc++.h>

using namespace std;
#define int long long
int n;
int a[200005], k, pref[200005], prv[200005], h[200005];
bool check(int l){
	for (int i = 1; i+l-1<=n; i++){
		if (prv[i]==prv[i+l-1]&&pref[i+l-1]-pref[i-1]<=k) return 1;
	}
	return 0;
}

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];	
		prv[i] = i;
	}
	for (int i = 1; i <= n; i++){
		cin >> h[i];
	}
	for (int i = 2; i <= n; i++){
		if (h[i-1]%h[i]==0) prv[i] = prv[i-1];
	}
	
	long long l = 1, h = n, m, res = 0;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			l = m+1;
			res = m;
		} else {
			h = m-1;
		}
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

