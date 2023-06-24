#include<bits/stdc++.h>

using namespace std;
int t, n, k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		for (int l = 1, h = n; l < h; l++, h--){
			cout << h << " " << l << " ";
		}
		if (n&1) cout << n/2+1 << "\n"; else cout << "\n";
	}
	
	return 0;
}
