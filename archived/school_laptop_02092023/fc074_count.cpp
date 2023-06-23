#include<bits/stdc++.h>

using namespace std;
const int p = 1e9+7;
int getPow(int x, long long y){
	int res = 1;
	while (y){
		if (y&1) res = 1ll*res*x%p;
		x = 1ll*x*x%p;
		y >>= 1;
	}
	return res;
}
long long n;
int main(){
	cin >> n;
	cout << getPow(3,n-1);
	
	return 0;
}
