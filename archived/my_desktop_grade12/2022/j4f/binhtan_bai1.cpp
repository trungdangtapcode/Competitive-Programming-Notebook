#include<bits/stdc++.h>

using namespace std;
#define int long long

const int XMAX = 1500000;

int f(int n){
	return 2*n + n*(n+1)*(2*n+1)/6-n;
}

main(){
	int n;
	cin >> n;
	int l = 0, r = XMAX, m,res = -1;
	while (l <= r){
		m = (l+r)/2;
		if (f(m)<=n){
			res = m;
			l = m+1;
		} else r = m-1;
	}
	cout << res;
	
	return 0;
}
