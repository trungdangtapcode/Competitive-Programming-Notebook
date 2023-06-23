#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, b;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> a >> b;
		int res = 1;
		for (int i = b; __gcd(i+1,a)!=1||i==b; i--) res = max(res,i/__gcd(i,a)*a);
		cout << res << "\n";
	}
	return 0;
}
