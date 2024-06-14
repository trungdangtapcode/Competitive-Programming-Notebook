#include<bits/stdc++.h>

using namespace std;
int n, a, b;
void solve(){
	cin >> n >>a >> b;
	int res = 0;
	if (2*a>=b) res += n/2*b, n %= 2;
	else res += a*n, n = 0;
	if (n%2) res += a;
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

