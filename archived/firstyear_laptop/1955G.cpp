#include<bits/stdc++.h>

using namespace std;
const int maxN = 105, maxA = 1e6+6;
vector<int> d[maxA];
int n, m, a[maxN][maxN], f[maxN][maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	int res = 0;
	for (int dv: d[__gcd(a[1][1],a[n][m])]){
		f[1][1] = 1;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				f[i][j] = i==1&&j==1;
				if (a[i][j]%dv) continue;	
				f[i][j] |= f[i-1][j]||f[i][j-1];
			}
		}
		if (f[n][m]) res = max(res,dv);
	}
	cout << res  << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 1e6; i++){
		for (int j = i; j <= 1e6; j += i) d[j].push_back(i);
	}
	
	int t; cin >> t;
	while (t--)
	solve();
}

