#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
long long f[5005][5005];
int n, q, a[5005], x, y; //cnt[5005][5005]
gp_hash_table<int,int> mp;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		mp.clear();
		for (int j = i+1; j <= n; j++){
			f[i][j] = mp[-(a[i]+a[j])];
			mp[a[j]]++;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = i-1; j > 0; j--){
			f[j][i] += f[j+1][i] + f[j][i-1] - f[j+1][i-1];
		}
	}
	while (q--){
		cin >> x >> y;
		cout << f[x][y] << "\n";
	}
	return 0;
}
