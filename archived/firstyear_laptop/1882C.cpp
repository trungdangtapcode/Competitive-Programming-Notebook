#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], f[maxN][2];
void solve(){
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	f[n+1][0] = f[n+1][1] = f[n][0] = f[n][1] = 0;
	for (int i = n-1; i >= 0; i--){
		f[i][0] = max({f[i+2][0],f[i+2][0]+a[i],f[i+1][0]+a[i],f[i+1][1]});
		f[i][1] = max({f[i+2][1],f[i+1][1],f[i+1][0]});
//		cout << f[i][0] << " " << f[i][1] << "\n";
	}
//	if (n%2&&a[n]>0) res += a[n];
//	for (int i = (n-1)/2*2; i >= 0; i -= 2){
//		cout << i << "a\n";
//		res += max({0,a[i]+a[i+1],a[i]}); 
//	}
	cout << f[0][0] << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
