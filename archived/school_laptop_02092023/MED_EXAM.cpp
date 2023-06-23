#include<bits/stdc++.h>
using namespace std;
#define int long long
main(){
	auto getPow = [](int a, int b){
		int res = 1;
		while (b){
			if (b&1) res = res*a;
			a = a*a;
			b >>= 1;
		}
		return res;
	};
	int b1, d1, b2, d2;
	cin >> b1 >> d1 >> b2 >> d2;
	int x = getPow(b1,d1-1), y = getPow(b1,d1)-1,  u = getPow(b2,d2-1), v = getPow(b2,d2)-1;
	cout << max(0ll,min(v,y)-max(u,x)+1);
	return 0;
}
