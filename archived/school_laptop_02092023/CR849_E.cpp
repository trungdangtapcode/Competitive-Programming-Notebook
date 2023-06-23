#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, f[200005][2], a[200005];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		f[0][0] = 0; f[0][1] = -1e9;
		f[1][0] = a[1], f[1][1] = -a[1];
		for (int i = 2; i <= n; i++) f[i][0] = max({f[i-1][0]+a[i],f[i-2][0]-a[i-1]-a[i],f[i-1][1]-a[i]}), 
			f[i][1] = max({f[i-1][0]-a[i],f[i-1][1]+a[i]});
		cout << f[n][0] << "\n";
	}
	
	
	return 0;
}
