#include<bits/stdc++.h>

using namespace std;
int n, a[100005];
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int res = 0;
		for (int l = 1, r = n; l < r; l++) if (a[l]){
			while (l<r&&a[r]) r--;
			if (l<r) res++;
			r--;
		}
		cout << res << "\n";
	}
	return 0;
}
