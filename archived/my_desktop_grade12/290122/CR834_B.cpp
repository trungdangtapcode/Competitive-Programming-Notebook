#include<bits/stdc++.h>

using namespace std;
int m, s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> m >> s;
		int sum = 0, mmax = 0;
		for (int i = 0, a; i < m; i++){
			cin >> a;
			sum += a;
			mmax = max(mmax,a);
		}
		bool res = false;
		for (;; mmax++){
			if (mmax*(mmax+1)/2-sum>s) break;
			if (mmax*(mmax+1)/2-sum==s) res = true;
		}
		cout << (res?"YES\n":"NO\n");
	}
	return 0;
}
