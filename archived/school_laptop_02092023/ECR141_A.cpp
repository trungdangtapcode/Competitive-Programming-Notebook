#include<bits/stdc++.h>

using namespace std;
int n, a[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a,a+n);
		reverse(a+1,a+n);
		if (*max_element(a,a+n)==a[0]) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0; i < n; i++) cout << a[i] << " ";
			cout << "\n";
		}
	}
	
	return 0;
}
