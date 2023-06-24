#include<bits/stdc++.h>

using namespace std;
int l, r, x, a, b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> l >> r >> x >> a >> b;
		if (a==b){
			cout << 0 << "\n";
		} else if (abs(a-b)>=x){
			cout << 1 << "\n";
		} else if (r-a>=x&&r-b>=x||a-l>=x&&b-l>=x){
			cout << 2 << "\n";
		} else if (r-a>=x&&r-l>=x&&b-l>=x||a-l>=x&&r-l>-x&&r-b>=x){
			cout << 3 << "\n";
		} else cout << -1 << "\n";
	}
	return 0;	
}
