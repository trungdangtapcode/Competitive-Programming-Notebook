#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int res = 1;
	for (int i = 0; i < n; i++) if (a[i]%2!=a[i%2]%2) res = 0;
	cout << (res?"YES\n":"NO\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

