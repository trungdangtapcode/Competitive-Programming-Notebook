#include<bits/stdc++.h>

using namespace std;
int n, k, p = 1e9+7;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		int res = 1;
		for (int i =0; i < k; i++) res = 1ll*res*n%p;
		cout << res << "\n";
	}
	
	return 0;
}
