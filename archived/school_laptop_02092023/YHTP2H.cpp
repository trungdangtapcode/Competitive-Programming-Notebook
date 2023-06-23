#include<bits/stdc++.h>

using namespace std;
int n, a[100005], x[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> x[i]; 
		for (int i = 0; i < n; i++){
			cin >> a[i];
			a[i] -= x[i];
		}
		sort(a,a+n);
		reverse(a,a+n);
		int res = 0;
		for (int i = 0, j = n-1; i < n; i++){
			while (i<j&&a[i]+a[j]<0) j--;
			if (i<j) res++, j--;
		}
		cout << res << "\n";
	}
	
	return 0;
}
