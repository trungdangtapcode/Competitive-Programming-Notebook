#include<bits/stdc++.h>

using namespace std;
#define int long long
int n;
void solve(){
	cin >> n;
	int s = 0, res = 0, mmax = 0;
	for (int i = 1; i <= n; i++){
		int a; cin >> a;
		s += a;
		mmax = max(mmax,a);
		if (s==mmax*2) res++;
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

