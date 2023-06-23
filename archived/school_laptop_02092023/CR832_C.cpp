#include<bits/stdc++.h>

using namespace std;
int n, a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> a;
		int mmin = a;
		for (int i = 1, x; i < n; i++){
			cin >> x;
			mmin = min(mmin,x);
		}
		cout << (mmin==a?"Bob\n":"Alice\n");
	}
	
	return 0;
}
