#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e4+5;
int a[maxN], k, x, y, n, m;
unordered_map<int,int> f[25], g[25];

int cost(int v){
//	cout << (v==k?x:y) << "\n";
	return (v==k?x:y);
}

void solve(){
	cin >> n >> m;
	cin >> k >> x >> y;
	for (int i = 1; i <= n; i++) cin >> a[i];
	f[0][a[1]] = 0; //id0 = 1
	for (int i = 2; i <= n+1; i++){
		for (int j = 0; j < m; j++)
			g[j].clear();
		int x = a[i];
		for (int j = 0; j < m; j++){
			for (auto it: f[j]){
				int d = it.first, val = it.second;
//				cout << i << ". m = " << j+1 << " d = " << d << ": " << val << "\n";
				if (j<m-1){
//					if (j+1==2&&d==2&&i==4) cout << j+2 << " " << x << " = " << val+cost(d) << "\n";
//					g[j+1][x] = val + cost(d);
//					if (j+1==2&&d==2&&i==4) break;
					if (g[j+1].count(x)){
						g[j+1][x] = min(g[j+1][x],val+cost(d));
					} else g[j+1][x] = val+cost(d);
				}	
//				if (j+1==3&&d==10) cout << "hi" << "\n";
				d = __gcd(d,x);
				if (g[j].count(d)){
					g[j][d] = min(g[j][d],val);
				} else g[j][d] = val;
//				g[j][d] = (g[j].count(d)?min(g[j][d],val):val);
			}
		}
//		for (int j = 0; j < m; j++) for (auto it: g[j]){
//			cout << it.first << "," << j+1 << ":" << it.second << "  ";
//		} cout << "\n";
		for (int j = 0; j < m; j++) f[j] = g[j];
//		for (int j = 0; j < m; j++) for (auto it: f[j]){
//			cout << it.first << "," << it.second << " ";
//		} cout << "\n\n";
	}
	int res = 1e18;
	for (auto it: f[m-1]){
		int d = it.first, val = it.second;	
		res = min(res,val+cost(d));
	}
	cout << res << "\n";
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

