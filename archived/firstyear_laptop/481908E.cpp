#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5+5;
int n, a[maxN], f[maxN], g[maxN], h[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//f[i] = f[j-1] + (i-j+1) => f[i]-i = f[j-1] - (j-1), g[i] = max(g[j]) with j<i and a[i] = a[j+1]
	for (int i = 1; i <= n; i++) f[i] = g[i] = h[i] = -1e9;
	int res = 0;
	for (int i = 1; i <= n; i++){
		f[i] = max(h[a[i]] + i,f[i-1]);
		res = max(res,f[i]);
		g[i] = f[i] - i;
		h[a[i]] = max(h[a[i]],g[i-1]); 
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
