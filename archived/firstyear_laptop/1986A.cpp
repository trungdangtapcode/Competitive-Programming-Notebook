#include<bits/stdc++.h>

using namespace std;
int a, b, c;
void solve(){
	cin >> a >> b >> c;
	int res = 1e9;
	for (int i = 0;i <= 10; i++){
		res = min(res,abs(a-i)+abs(b-i)+abs(c-i));
	}
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

