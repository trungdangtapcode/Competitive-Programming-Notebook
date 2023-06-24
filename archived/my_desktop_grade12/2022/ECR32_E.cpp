#include<bits/stdc++.h>

using namespace std;
int n, m, a[35], b[35], n1, n2;
main(){
	set<int> s;
	cin >> n >> m;
	for (int i = 0; i < n/2; i++) cin >> a[n1++];
	for (int i = n/2; i < n; i++) cin >> b[n2++];
	for (int mask = 0; mask < (1<<n1); mask++){
		int cur = 0;
		for (int i = 0; i < n1; i++) if (mask>>i&1) (cur += a[i])%=m;
		s.insert(cur);
	}
	int res =0;
	for (int mask = 0; mask < (1<<n2); mask++){
		int cur = 0;
		for (int i = 0; i < n2; i++) if (mask>>i&1) (cur += b[i])%=m;
		res = max(res,(*s.rbegin()+cur)%m);
		auto it = s.lower_bound(m-cur);
		if (it!=s.begin()) it--;
		res = max(res,(*it+cur)%m);
	}
	cout << res;
	
	return 0;
}
