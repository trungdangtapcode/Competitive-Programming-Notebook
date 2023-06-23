#include<bits/stdc++.h>

using namespace std;
int n, c, a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> c;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			a[i] += i;
		}
		sort(a+1,a+n+1);
		int res = 0;
		for (int i = 1; i<= n; i++){
			if (c<a[i]) break;
			c -= a[i];
			res++;
		}
		cout << res << "\n";
	}
	
	return 0;
}
