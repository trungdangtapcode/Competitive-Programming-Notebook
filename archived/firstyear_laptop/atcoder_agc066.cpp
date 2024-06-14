#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5, T = 2e6;
int n, f[maxN], g[maxN*4], h[maxN*4], pref[maxN], a[maxN];
string s;
void solve(){
	cin >> s;
	n = s.length();
	s = " " + s;
	for (int i = 1; i <= n; i++) a[i] = s[i] - 'A', pref[i] = pref[i-1] + (a[i]==0?1:-2);
//	for (int i = 0; i <= 2*T; i++) g[i] = h[i] = 1e9;
	for (int i = -2*n; i <= n; i++) g[i+T] = h[i+T] = 1e9;
	f[0] = 0;
	g[0+T] = 0;
	if (a[1]==1) h[0+T] = 0;
	for (int i = 1; i <= n; i++){
		int x = pref[i];
		f[i] = f[i-1] + 1;
		
		f[i] = min(f[i], h[x+T]);
		if (a[i]==1) f[i] = min(f[i], g[x+T]);
		
		g[x+T] = min(g[x+T], f[i]);
		if (a[i+1]==1) h[x+T] = min(h[x+T], f[i]);
//		cout << f[i] << " " << pref[i] << "\n";
	}
	int res = (n-f[n]);
	cout << res/3 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}


/*
for (int i = 1; i <= n; i++) for (int j = 0; j < 4; j++) f[i][j] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 4; j++){
			int new_j = (a[i]?);
			f[i][j] = max(f[i][j],f[i-1][])
			if (i<2) continue;
			
			if (i<3) continue;
		}
	}
*/
