#include<bits/stdc++.h>

using namespace std;
#define int long long
int spf[1000005], n, k, a;

bool check(int n, int a, int k){
	map<int,int> mp;
	while (a>1){
		mp[spf[a]]+=k;
		a /= spf[a];
	}
	for (auto it: mp){
		int cur = 0, p = it.first, cnt = it.second, tmp = n;
		while (tmp>1){
			cur += (tmp/p);
			tmp /= p;
		}
		if (cur<cnt) return 0;
	}
	return 1;
}

main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	for (int i = 1; i <= 1e6; i++) spf[i] = i;
	for (int i = 2; i*i <= 1e6; i++) if (spf[i] == i) for (int j = i*i; j <= 1e6; j+=i) spf[j] = i;
	
	int t; cin >> t;
	while (t--){
		cin >> a >> k;
		int l = 0, h = 1e18, m, res;
		while (l<=h){
			m = (l+h)/2;
			if (check(m,a,k)){
				h = m-1;
				res = m;
			} else l = m+1;
		}
		cout << res << "\n";
	}
	
	return 0;
}
