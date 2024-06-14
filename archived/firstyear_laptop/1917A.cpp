#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];	
	}
	int cnt = 0, res = -1;
	for (int i = 1; i <= n; i++){
		if (a[i]==0){
			cout << 0 << "\n";
			return;
		}	
		if (a[i]<0) cnt ^= 1;
	}
	if (cnt){
		cout << 0 << "\n";
	} else {
		cout << 1 << "\n";
		cout << 1 << " " << 0 << "\n"; 
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}
