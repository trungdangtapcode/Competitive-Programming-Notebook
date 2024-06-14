#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, k, check[maxN];
string s;
void solve(){
	cin >> n >> s >> k;
	for (int i = 0; i < n; i++) check[i] = 0;
	for (int i = 1; i <= k; i++){
		char c;
		cin >> c;
		for (int j = 0; j < n; j++) if (s[j]==c) check[j] = 1;
	}
	int last = 0, res = 0;
	for (int i = 0; i < n; i++) if (check[i]) res = max(res, i-last),last = i;
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

