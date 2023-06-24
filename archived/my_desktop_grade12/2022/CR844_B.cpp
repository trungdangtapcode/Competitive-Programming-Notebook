#include<bits/stdc++.h>

using namespace std;
int n, a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1,a+n+1);
		int res = 1 + (a[1]>0);
		for (int i = 1; i < n; i++) res += (a[i]<=i-1&&i<a[i+1]);
		cout << res << "\n";
	}
	
	return 0;
}
