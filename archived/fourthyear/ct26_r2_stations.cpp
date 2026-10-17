#include<bits/stdc++.h>

using namespace std;
const int N = 2005;
int n, a[N], b[N], k;
long long f[N][N], g[N][N]; // f[tram i][j cai thuoc doi 1], g
// f -> 1, g -> 2
// f[i][j] = a_i+min(f[i-1][j-1], g[i-1][j-1]+b_i)
// g[i][j] = min(g[i-1][j], f[i-1][j]+b_i))
// f[i][j] = min()


void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) cin >> b[i];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) f[i][j] = g[i][j]= 1e18;
	f[1][1] = 0;
	g[1][0] = a[1];
	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= k; j++){
			if (j) f[i][j] = min(f[i-1][j-1], g[i-1][j-1]+b[i-1]);
			g[i][j] = a[i]+min(g[i-1][j], f[i-1][j]+b[i-1]);
		}
	}
	cout << min(f[n][k], g[n][k]);
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

