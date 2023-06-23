#include<bits/stdc++.h>

using namespace std;
long long int n, x;
const int p = 1e9+7;
map<long long int, int> memo;
int lt(long long int a, long long int b){
	a %= p;
	int res = 1;
	while (b){
		if (b&1) res = 1ll*res*a%p;
		b /= 2;
		a = 1ll*a*a%p;
	}
	return res;
}
int f(long long int l, long long int r){
	if (r<l) return 0;	
	if (l==r) return 1;
	if (memo.count(r-l)) return memo[r-l];
	long long int m = (l+r)/2;
	return memo[r-l] = (1ll*f(l,m-1)*(n%p-x%p)%p*lt(n,r-m)%p + lt(n,r-l) + 1ll*f(m+1,r)*(x%p-1%p)%p*lt(n,m-l)%p)%p;
}

int main(){
	cin >> n >> x;
	cout << (f(1,n)+1ll*p*p)%p;
	
	return 0;
}
