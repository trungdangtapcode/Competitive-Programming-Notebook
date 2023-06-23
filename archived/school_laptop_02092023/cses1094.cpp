#include<bits/stdc++.h>

using namespace std;
int n, mmax;
int main(){
	cin >> n >> mmax;
	long long int res = 0;
	for (int i = 1, a; i < n; i++){
		cin >> a;
		if (mmax>a) res += mmax-a;
		mmax = max(mmax,a);
	}
	cout << res;
	
	return 0;
}
