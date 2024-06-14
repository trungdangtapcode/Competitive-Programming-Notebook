#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e3+5, maxK = 1e5+5;
int n, a[maxN], d, k, v[maxK];
int calc(int x){
	int tmp = 0;
	for (int i = 1; i <= n; i++) tmp += a[i]==i;
	x++;
	if (x>d) return 0;
	int rem = d-x;
	return (rem)/2+tmp;
}
void solve(){
	cin >> n >> k >> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= k; i++){
		cin >> v[i];
	}
	int res = calc(0);
//	cout << 0 << ": " << calc(0) << "\n";
	for (int i = 1; i <= min(d,2*n+5); i++){
		for (int j = 1; j <= v[(i-1)%k+1]; j++) a[j]++;
		res = max(res,calc(i));
//		cout << i << ": " << calc(i) << "\n";
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}
