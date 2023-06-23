#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, b, d;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> a >> b >> d;
		int k = 0;
		a|= b;
		while (a%2==0&&d%2==0) a/=2, d/=2, k++;
		if (d%2==0){
			cout << -1 << "\n";
			continue;
		}
		int inv2 = (d+1)/2;
		int p = 1;
		for (int i = 0; i < 30-k; i++) p = p*inv2%d;
		p = ((p-1+d)%d);
		cout << (p<<30) + (((1ll<<(30-k))-1)<<k) << "\n";
	}
	
	return 0;
}
