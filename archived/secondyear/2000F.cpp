#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n, f[maxN][maxN], a[maxN], b[maxN], k;
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for (int i = 1; i <= n; i++) if (a[i]<b[i]) swap(a[i],b[i]);
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) f[i][j] = 1e9;
	f[0][0] = 0;
	for (int i = 1; i <= n; i++){
		int w = a[i], h = b[i];
		for (int j = 0; j <= k; j++) if (f[i-1][j]!=1e9){
//			cout << i-1 << " " << j << " = " << f[i-1][j] << "\n";
			f[i][j] = min(f[i-1][j],f[i][j]);
			int point = j, cost = 0;
			for (int col = 0; col < w-h; col++){
				cost += h;
				point++;
				if (point<=k)
					f[i][point]= min(f[i-1][j]+cost,f[i][point]);
			}
			for (int l = h; l > 0; l--){
				cost += l;
				point++;
				if (point<=k)
					f[i][point]= min(f[i-1][j]+cost,f[i][point]);
				cost += l-1;
				point++;
				if (point<=k)
					f[i][point]= min(f[i-1][j]+cost,f[i][point]);
			}
		}
	}
	cout << (f[n][k]<1e9?f[n][k]:-1) << "\n";
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

