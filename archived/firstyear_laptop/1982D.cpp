#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e2+5;
int n, m, k, a[maxN][maxN], pref[maxN][maxN];
char c[maxN][maxN];
int gets(int x, int y, int u, int v){
	return pref[u][v]-pref[u][y-1]-pref[x-1][v]+pref[x-1][y-1];
}
void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> c[i][j];
	}
	int diff = 0, g = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			diff += (c[i][j]=='1'?1:-1)*a[i][j];
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + (c[i][j]=='1'?1:-1);
//			cout << pref[i][j] << " ";
		}
//		cout << "\n";
	}
	vector<int> v;
	for (int i = 1; i <= n-k+1; i++){
		for (int j = 1; j <= m-k+1; j++){
			int s = gets(i, j, i+k-1, j+k-1);
			v.push_back(abs(s));
//			cout << s << " ";
		}
//		cout << "\n";
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for (int x: v){
//		cout << x << " ";
		g = __gcd(x,g);
	}
	if (diff==0&&g==0){
		cout << "YES\n";
	} else {
		if (g==0||diff%g) cout << "NO\n";
		else cout << "YES\n";
	}
//	cout << (g==0&&||diff%g?"NO":"YES") << diff << "\n";
	
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

