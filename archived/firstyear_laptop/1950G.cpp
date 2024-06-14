#include<bits/stdc++.h>

using namespace std;
const int maxN = 16;
int n, f[(1<<maxN)+5][maxN+5], x[maxN+5], y[maxN+5];
map<string, int> gm, wm;
void solve(){
	gm.clear();
	wm.clear();
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int mask = 0; mask < (1<<n); mask++) f[mask][i] = 0; 
		string g, w;
		cin >> g >> w;
		if (!gm.count(g)) gm[g] = gm.size();
		if (!wm.count(w)) wm[w] = wm.size();
		x[i] = gm[g];
		y[i] = wm[w];
		f[1<<i][i] = 1;
	}
	int res = 0;
	for (int mask = 0; mask < (1<<n); mask++) for (int last = 0; last < n; last++) if (f[mask][last]){
		for (int i = 0; i < n; i++) if (!(mask>>i&1)){
			int nmask = (mask)|(1<<i);
			if (x[last]!=x[i]&&y[last]!=y[i]) continue;
			f[nmask][i] = 1;
		}
		res = max(res,__builtin_popcount(mask));
	}
	
	cout << n-res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

