#include<bits/stdc++.h>

using namespace std;
int n, a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a+1,a+n);
		for (int i = 1; i < n; i++) if (a[i]>a[0]){
			int d = (a[i]-a[0]+1)/2;
			a[i] -= d;
			a[0] += d;
		}
		cout << a[0] << "\n";
	}
	
	
	return 0;
}
