#include<bits/stdc++.h>

using namespace std;
int n, a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		int sum = 0, res = 1e9;
		for (int i = 1; i <= n; i++){
			cin >> a;
			sum += a;
			int t = a%2, cur = 0;
			while (a%2==t&&a) a/= 2, cur++;
			if (a%2!=t) res = min(res,cur);
		}
		if (sum%2==0) cout << 0 << "\n";
		else cout << res << "\n";
	}
	
	
	return 0;
}
