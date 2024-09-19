#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int l, n, q, a[maxN];
void solve(){
	cin >> l >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	while (q--){
		int x; cin >> x;
		int pos = lower_bound(a+1,a+n+1,x)-a;
		if (pos==1){
			cout << a[pos]-1 << "\n";
			continue;
		}
		if (pos==n+1){
			cout << l-a[pos-1] << "\n";
			continue;
		}
		int d = a[pos]-a[pos-1]-1;
		cout << (d+1)/2 << "\n";
	}
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

