#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	};
	sort(a+1,a+n+1);
	int p = a[n/2+1];
	long long res = max(2ll*p*n-sum+1,0ll);
	cout << (n<3?-1:res) << "\n";
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

