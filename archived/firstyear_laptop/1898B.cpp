#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
string s;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int last = a[n];
	int res = 0;
	for (int i = n-1; i > 0; i--){
		int cnt = (a[i]+last-1)/last;
		res += cnt-1;
		last = a[i]/cnt;
//		res += (a[i]%last?a[i]/last:a[i]/last-1);
//		last = (a[i]%last?a[i]%last:last);
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
