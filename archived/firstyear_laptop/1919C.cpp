#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	int res = 0;
	cin >> n;
	int lasta = 1e9, lastb = 1e9;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (lasta>=a[i] && lastb>=a[i]){
			if (lasta<lastb) lasta = a[i];
			else lastb = a[i];
		} else if (lasta>=a[i]){
			lasta = a[i];
		} else if (lastb>=a[i]){
			lastb = a[i];
		} else {
			res++;
			if (lasta<lastb) lasta = a[i];
			else lastb = a[i];
		}
//		cout << lasta << " " << lastb << " " << res << "\n";
	}
	cout << res << "\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
