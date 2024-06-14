#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], b[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i];
	}
	int res = 0;
	for (int i = 1, j = 1; i <= n; i++, j++){
		while (j<=n&&a[i]>b[j]) j++, res++;
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

