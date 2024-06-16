#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, q;
typedef pair<int,int> ii;
ii a[maxN];
void solve(){
	cin >> n>> q;
	for (int i = 1; i <= n; i++) cin >> a[i].second >> a[i].first;
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) a[i].second += a[i-1].second;
//	for (int i = 1; i <= n; i++) cout << a[i].first << "," << a[i].second << "\n";
	for (int i = 1; i <= q; i++){
		int x; cin >> x;
		ii tmp = {x,1e18};
		int pos = upper_bound(a+1,a+n+1, tmp) - a - 1;
//		cout << pos << " => ";
		cout << a[pos].second << "\n";
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
//	int t; cin >> t;
//	while (t--)
	solve();
}

