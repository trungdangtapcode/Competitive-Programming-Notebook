#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n,0);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(),a.end());
		int res = -2e9;
		for (int i = 2; i < n; i++) res = max(res,a[i]-a[i-1]+a[i]-a[0]);
		for (int i = 0; i < n-2; i++) res = max(res,a[i+1]-a[i]+a[n-1]-a[i]);
		cout << res << "\n";
	}
	
	return 0;
}
