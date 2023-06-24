#include<bits/stdc++.h>

using namespace std;
int n;
long long a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			a[i] += a[i-1];
		}
		long long res = 0;
		for (int i = 1; i < n; i++){
			res = max(res,__gcd(a[i],a[n]-a[i]));
		}
		cout << res << "\n";
	}
	
	return 0;
}
