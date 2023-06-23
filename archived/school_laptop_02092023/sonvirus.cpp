#include<bits/stdc++.h>

using namespace std;
#define int long long
const int p =1e9+7;
int getPow(int a, int b){
	int res = 1;
	while (b){
		if (b&1) res = res*a%p;
		a = a*a%p;
		b >>= 1;
	}
	return res;
}
main(){
	int n, k;
	cin >> n;
	k = n/3+1;
	if (n%3==2) cout << getPow(2,n)-getPow(2,k);
	else cout << getPow(2,n);
	
	return 0;
}
