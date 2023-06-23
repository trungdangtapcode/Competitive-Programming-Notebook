#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[200005], g, ones;
const int p = 998244353; 	
int inv(int x){
	x %= p;
	int b = p-2, res = 1;
	while (b){
		if (b%2) res = res*x%p;
		b /= 2;
		x = x*x%p;
	}
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		ones = g = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			g += (a[i]==0);
		}
		for (int i = 1; i <= g; i++){
			ones += (a[i]==1);
		}
		int res = 0;
		//remove all ones in first g position
		for (int i = ones; i >= 1; i--){
			int prob = n*(n-1)%p*inv(2*i*i)%p;
			res += prob;
		}
		cout << res%p << "\n";
	}
	
	
	return 0;
}
