#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 1e18;
	for (int i = 1; i <= n; i++){
		int cur = 0;
		for (int j = i-1, last = 0; j >= 1; j--){
			cur += last/a[j]+1;
			last = (last/a[j]+1)*a[j];
		}
		for (int j = i+1, last = 0; j <= n; j++){
			cur += last/a[j]+1;
			last = (last/a[j]+1)*a[j];
		}
		res = min(res,cur);
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

