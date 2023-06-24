#include <bits/stdc++.h>

using namespace std;
int n, q;
vector<int> a;
int main(){
	freopen("DIEMSO.INP","r",stdin);
	freopen("DIEMSO.OUT","w",stdout);
	
	cin >> n;
	a.assign(n,0);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> q;
	while (q--){
		int x, y;
		long long int mmax = -1e18, last = 0;
		cin >> x >> y;
		x--; y--;
		for (int i = x; i <= y; i++){
			if (last<0) last = 0;
			last += a[i];
			mmax = max(mmax,last);
		}
		cout << mmax << '\n';
	}
	
	return 0;
}
