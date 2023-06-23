#include<bits/stdc++.h>

using namespace std;
int n, a[500005], p[500005], m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
//	int t = 1;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		iota(p,p+n,0);
		sort(p,p+n,[&a](int x, int y){ return a[x] < a[y];});
		int cur = 0, m0 = m;
		for (int i = 0; i < n; i++){
			if (m0<a[p[i]]) break;
			m0 -= a[p[i]];
			cur++;
		}
		if (cur>=n){
			cout << 1 << "\n";
			continue;
		}
		if (cur==0){
			cout << n+1 << "\n";
			continue;
		}
		m -= a[cur];
		a[cur] = 1e9;
		int cur2 = (m>=0);
		for (int i = 0; i < n; i++){
			if (m<a[p[i]]) continue;
			m -= a[p[i]];
			cur2++;
		}
		if (cur2==cur) cur++;
		cout << n-cur+1 << "\n";
	}
	
	return 0;
}
