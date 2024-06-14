#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, a[maxN], b[maxN];
void solve(){
	multiset<int,greater<int>> ms;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i];
	}
	a[n+1] = b[n] = 0;
	for (int i = n; i > 0; i--){
		a[i] += a[i+1];
	}
	ms.insert(0);
	for (int i = n-1; i > 0; i--){
		b[i] += b[i+1];
		ms.insert(b[i]);
	}
	int res = -1e18;
	for (int i = n; i > 0; i--){
		res = max(a[i] - *ms.begin(),res);
		ms.insert(b[i]+2*a[n]);
		ms.erase(ms.find(b[i]));
	}
	cout << res << "\n";
}
main(){
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
