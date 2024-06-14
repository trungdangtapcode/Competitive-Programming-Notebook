#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;
int n, a[maxN];
long long g[maxN];
int check[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++){
		g[i] = check[i] = 0;
	}
	long long res = 0;
	for (int i = 1; i <= n; i++){
//		f[i] = g[a[i]];
//		for (int x: d[a[i]]){
//			g[x]++;
//		}
		g[a[i]]++;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 2*i; j <= n; j+= i) g[i] += g[j];
	}
	for (int i = n; i >= 1; i--){
		g[i] = g[i]*(g[i]-1)/2;
		for (int j = 2*i; j <= n; j += i) g[i] -= g[j];
//		cout << i << " = " << g[i] << '\n';
	}
	for (int i = 1; i <= n; i++){
		long long cur = 0;
		if (!check[a[i]])for (int j = a[i]; j <= n; j+= a[i]){
			check[j] = 1;
			cur += g[j];
			g[j] = 0;
		}
		res += cur;
	}
	cout << 1ll*n*(n-1)/2-res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
