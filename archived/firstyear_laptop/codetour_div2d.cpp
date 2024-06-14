#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e3+5;
int n, k, d, t[maxN], a[maxN], b[maxN], last[maxN], f[maxN][maxN];
void solve(){
	cin >> n >> k >> d;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i <= k; i++){
		last[i] = -1;
		cin >> a[i];
	}
	int res = 1e9;
	for (int i = 1; i <= k; i++){
		cin >> b[i];
	}
	int INF = 1e9;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = INF;
	f[1][1] = a[1];
	last[t[1]] = 1;
	for (int i = 2; i <= n; i++){
		int prv = last[t[i]];
		cout << prv << "\n";
		for (int j = 1; j <= min(i,d); j++) {
			cout << i << ", " << j << ": " << f[i-1][j] << " " << prv << " " << i-1-j+1 << "\n";
			if (prv!=1&&prv>=i-1-j+1&&j<d) f[i][j+1] = min(f[i][j+1],f[i-1][j]+b[t[i]]);
			else 
			f[i][1] = min(f[i][1],f[i-1][j]+a[t[i]]); 
		}
		last[t[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		cout << i << ": ";
		for (int j = 1;j <=  d; j++) cout << f[i][j] << " ";
		cout << "\n";
	}
	
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

