#include<bits/stdc++.h>

using namespace std;
int n, a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> a[0];
		int l = 0, h = 1e9;
		for (int i = 1, u, v; i < n; i++){
			cin >> a[i];
			if (a[i]>a[i-1]) u = (a[i]+a[i-1])/2, h = min(h,u);
			else if (a[i]<a[i-1]) v = (a[i]+a[i-1]+1)/2, l = max(l,v);
		}
		if (l<=h) cout << (l+h)/2 << "\n";
		else cout << -1 << "\n";
	}
	
	return 0;
}
