#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5, mod = 1e9+7;
int n, k, a[maxN];	
void solve(){
	cin >> n >> k;
	int res = 0;
	int base = 1;
	for (int i = 0, sum = 0; i < n; i++){
		cin >> a[i];
		sum = max(sum,0ll);
		sum += a[i];
		res = max(res,sum);
	}
	int tmp = res;
	for (int i = 0; i < k; i++) res = 2*res%mod;
	res -= tmp;
	for (int i = 0; i <n; i++) res += a[i];
	res %= mod;
	res += mod;
	cout << res%mod << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

