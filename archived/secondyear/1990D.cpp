#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], f[maxN][17];
void solve(){
	cin >> n;
	for (int i = 1; i<= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) for (int mask = 0; mask < 16; mask++) f[i][mask] = 1e9;
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) for (int mask = 0; mask < 16; mask++){
		f[i][0] = min(f[i][0],f[i-1][mask]+1);
		if (a[i]<=4){
			int empty = mask, nmask = 0, cnt = 0;
			for (int j = 0; j < a[i]; j++){
				if (empty>>j&1) continue;
				empty |= (3<<j); 
				nmask |= (3<<j);
				cnt++;
			}
//			cout << bitset<4>(mask) << " ->" << bitset<4>(nmask) << " = " << cnt << "\n";
			nmask &= 15;
			f[i][nmask] = min(f[i][nmask],f[i-1][mask]+cnt);
		}
	}
//	return;
//	for (int i = 1;i <= n; i++){
//		cout << i << ":\n";
//		for (int mask = 0; mask < 16; mask++)
//			cout << bitset<4>(mask) << " " << f[i][mask] << "\n";
//	}
	int res = 1e9;
	for (int mask = 0; mask < 16; mask++) res = min(res,f[n][mask]);
	cout << res << "\n";
//	cout << f[n] << '\n';
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

