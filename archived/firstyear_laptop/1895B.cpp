#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= 2*n; i++) cin >> a[i];
	sort(a+1,a+2*n+1);
	int res = 0;
	for (int i = 1; i <= 2*n; i++){
		res += (i!=n&&i!=2*n)*(a[i+1]-a[i]);
	}
	cout << res << "\n";
	for (int i = 1; i <= n; i++){
		cout << a[i] << " " << a[i+n] << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
