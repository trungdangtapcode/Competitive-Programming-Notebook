#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[15], k;
vector<int> v;
int cnt(int x){
	int res = 0;
	for (int y: v) res += x/y;
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		v.clear();
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < (1<<n); i++){
			int tmp = 1, sign = 1;
			for (int j = 0; j < n; j++) if (i&(1<<j)){
				sign *= -1;
				if (tmp==1) tmp = a[j];
				else tmp = (tmp/__gcd(tmp,a[j])*a[j]);
			}
//			cout << tmp << endl;
			v.push_back(sign*tmp);
		}
		int l = 0, h = 1e18, m, res;
		while (l<=h){
			m = (l+h)/2;
			if (cnt(m)>=k){
				res = m;
				h = m-1;
			} else l = m+1;
		}
		cout << res << "\n";
	}
//	cout << cnt(1);
	
	return 0;
}
