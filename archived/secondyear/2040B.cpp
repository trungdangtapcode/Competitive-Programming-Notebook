#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	int res = 1;
	for (int i = 1; i < n; i = 2*i+2, res++);
	cout << res << "\n";
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

