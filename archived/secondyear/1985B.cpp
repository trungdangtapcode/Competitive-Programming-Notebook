#include<bits/stdc++.h>

using namespace std;
int n;
int f(int x){
	int k = n/x;
	return k*(k+1)/2*x;
}
void solve(){
	cin >> n;
	int res = 2;
	for (int x = 3; x <= n; x++) if (f(x)>f(res)) res = x;
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

