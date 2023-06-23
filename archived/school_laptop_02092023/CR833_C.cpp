#include<bits/stdc++.h>

using namespace std;
#define int long long
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; 
	while (t--){
		int n; cin >> n;
		map<int,int> mp;
		int sum = 0, mmax = 0, res = 0;
		bool has_zero = false;
		for (int i = 1, x; i <= n; i++){
			cin >> x;
			if (x==0){
				if (has_zero) res+=mmax;
				else res+=mp[0];
				has_zero = true;
				mmax = 0;
				mp.clear();
			}	
			sum += x;
			mmax = max(mmax,++mp[sum]);
		}
		if (has_zero) res+=mmax;
		else res+=mp[0];
		cout << res << "\n";
	}
	
	return 0;
}
