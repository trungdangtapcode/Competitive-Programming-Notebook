#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e3+5;
int n, x[maxN], g[maxN], cnt[maxN];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
		if (x[i]<=5e3) cnt[x[i]]++;
//		for (int j = 1; j <= 5e3+1; j++) f[i][j] = 1e9;
	}
	int mex = -1;
	for (int i = 0; i <= n; i++) if (cnt[i]==0){
		mex = i;
		g[mex] = 0;
		break;
	}
//	int res = 1e9;
	for (int i = mex-1; i > -1; i--){
//		g[i] = g[i+1];
		g[i] = 1e9;
		for (int j = i+1; j <= mex; j++){
			g[i] = min(g[i],g[j]+j*(cnt[i]-1)+i);
		}
//		res = min(res,g[i]);
//		cout << i << "."  << g[i] << "\n";
	}
	cout << g[0] << "\n";
	for (int i = 1; i <= n; i++) if (x[i]<=5e3) cnt[x[i]]--;
}

main(){
//	solve();
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	
	return 0;
}
