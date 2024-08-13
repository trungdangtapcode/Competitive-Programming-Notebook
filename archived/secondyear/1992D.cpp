#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+15;
int n, m, k, f[maxN];
char c[maxN];
void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		f[i] = -1;
	}
	f[n+1] = -1;
	f[0] = k;
	c[0] = 'L';
	for (int i = 0; i <= n; i++){
		if (c[i]=='C') continue;
		if (c[i]=='L') for (int j = 1; j <= m; j++){
			f[i+j] = max(f[i+j],f[i]);
		}
		if (c[i]=='W') f[i+1] = max(f[i+1],f[i]-1);
	}
	cout << (f[n+1]>=0?"YES":"NO") << "\n";
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

