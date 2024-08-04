#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+6;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long f = 0, res = a[n];
	a[n+1] = 0;
	for (int i = n-1; i >= 1; i--){
		if (a[i+1]>=a[i]){
			f += a[i+1]-a[i]+1;	
		} else f = 0;
		res = max(res,f + a[i] + i - 1);
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

