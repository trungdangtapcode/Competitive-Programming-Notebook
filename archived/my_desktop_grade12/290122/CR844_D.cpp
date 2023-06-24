#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[55];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int res = 1;
		for (int i = 0; i < n; i++){
			map<int,int> mp;
			for (int j = i+1; j < n; j++){
				int diff = a[j] - a[i];
				for (int k = 1; k*k <= diff; k++) if (diff%k==0){
					int sum = k, dif = diff/k;
					if (sum<dif) swap(sum,dif);
					if ((sum-dif)%2) continue;
					int a2 = (sum-dif)*(sum-dif)/4;
					int x = a2 - a[i];
					if (x<0) continue;
					mp[x]++;
					res = max(res,mp[x]+1);
				}
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}
