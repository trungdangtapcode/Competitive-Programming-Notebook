#include<bits/stdc++.h>

using namespace std;
const int maxN = 21, mod = 1e9+7;
int n, a[maxN][maxN], f[1<<maxN];
//vector<int> adj[maxN];
void solve(){
	cin >> n;
	for (int i = 0; i < n;i++) for (int j = 0; j< n; j++){
		cin >> a[i][j];
//		if (a[i][j]) adj[i].push_back(j);
	}
	f[0] = 1;
	for (int mask = 0; mask<(1<<n); ++mask){
		int i = __builtin_popcount(mask);
		for (int j = 0; j < n; ++j) if (a[i][j]&&((mask>>j&1)==0)){
//			for (int j: adj[i]) if ((mask>>j&1)==0){
			int nmask = mask^(1<<j);
			f[nmask] += f[mask];			
			if (f[nmask]>mod) f[nmask] -= mod;
		}
	}
//		for (int mask = 0; mask < (1<<n); ++mask) 
//			cout << i << ". " << bitset<4>(mask) << " " << f[mask] << "\n";
//	}
	cout << f[(1<<n)-1] << '\n';
}

int32_t main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

