#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, b, m;
void solve(){
	cin >> a >> b >> m;
	cout << m/a + m/b + 2 << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

