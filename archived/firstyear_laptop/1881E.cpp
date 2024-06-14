#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], f[maxN], g[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	reverse(a+1,a+n+1);
//	for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
	for (int i = 1; i <= n; i++){
		f[i] = f[i-1]+1;
		if (i>a[i]) f[i] = min(g[i-a[i]-1] + i-a[i]-1,f[i]);
		g[i] = f[i] - i;
		g[i] = min(g[i],g[i-1]);
	}
	cout << f[n] << "\n";
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

