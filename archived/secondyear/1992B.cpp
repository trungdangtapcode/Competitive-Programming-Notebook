#include<bits/stdc++.h>

using namespace std;
int n, a, s;
void solve(){
	cin >> s >> n;
	int mmax = 0;
	for (int i = 1; i <= n; i++){
		cin >> a;
		mmax = max(mmax, a);
	}
	cout << 2*(s-mmax)-(n-1) << '\n';
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

