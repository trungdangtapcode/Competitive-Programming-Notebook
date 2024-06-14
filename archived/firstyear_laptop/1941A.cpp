#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e3+5;
int n, m, k, a[maxN];
void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 0;
	for (int i = 1, b; i <= m; i++){
		cin >> b;
		for (int j = 1; j <= n; j++) res += (b+a[j]<=k); 
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

