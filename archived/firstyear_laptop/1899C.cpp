#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
//		a[i] += a[i-1];
	}
	int res = a[1], cur = a[1];
	for (int i = 2; i <= n; i++){
		if (abs(a[i])%2!=abs(a[i-1])%2){
			cur = max(cur,(int)0);
			cur += a[i];
			res = max(res,cur);	
		} else{
			cur = a[i];
			res = max(res,cur);
		}
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
