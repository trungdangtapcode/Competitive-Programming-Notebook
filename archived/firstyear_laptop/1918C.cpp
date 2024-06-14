#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		long long a, b, r;
		cin >> a >> b >> r;
//		cout << bitset<10>(a) << " " << bitset<10>(b) << "\n";
		if (a<b) swap(a,b);
		for (int i = 60, eq = 1; i >= 0; i--){
			int ca = (a>>i)&1, cb = (b>>i)&1;
			if (cb>=ca) continue;
			if (eq==1||r<(1ll<<i)){
				eq = 0;
				continue;
			}
			r -= (1ll<<i);
			a ^= (1ll<<i);
			b ^= (1ll<<i);
		}
//		cout << a << " " << b << "\n";
		cout << abs(a-b) << "\n";
	}
	
}
