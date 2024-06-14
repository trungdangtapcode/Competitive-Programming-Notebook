#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 3e5+5;
int n, k, a[maxN], f[maxN][11];
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) for (int cnt = 0; cnt <= k; cnt++){
		int mmin = 1e9;
		f[i][cnt] = 1e18;
		for (int j = i; j >= max(1ll,i-cnt); j--){
			mmin = min(mmin,a[j]);
			f[i][cnt] = min(f[i][cnt],f[j-1][cnt-(i-j)]+mmin*(i-j+1));
		}
		
	}
	cout << f[n][k] << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

