#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a, b, d[maxN];
void solve(){
	cin >> n >> a >> b;
	int mmax = 0;
	for (int i = 0; i < n; i++){
		cin >> d[i];
		d[i] %= a+b;
	}
	sort(d,d+n);
//	for (int i = 0; i < n; i++) mmax = max(mmax,(d[(i+1)%n]-d[i]-1+a+b)%(a+b));
	for (int i = 1; i < n; i++) mmax = max(mmax, d[i]-d[i-1]-1);
	mmax = max(mmax,d[0]+a+b-d[n-1]-1);
	cout << (a+b-mmax<=a?"Yes\n":"No\n");
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

