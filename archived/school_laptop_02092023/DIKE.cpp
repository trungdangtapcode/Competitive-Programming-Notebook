#include<bits/stdc++.h>

using namespace std;
#define int long long
int n;
int f(int k){
	return (k+1)*k*k/2  - k*(k-1)/2 - (2*k-1)*k*(k-1)/6 + k*(k+1)/2 - 1;
}

main(){
	cin >> n;
	int l = 0, h = 2e6, m, res;
	while (l<=h){
		m = (l+h)>>1;
		if (f(m)<=n){
			res = m;
			l = m+1;
		} else h = m-1;
	}
	cout << res;
	
	return 0;
}
