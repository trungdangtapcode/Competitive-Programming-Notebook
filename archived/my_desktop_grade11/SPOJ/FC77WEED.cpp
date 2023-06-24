#include <bits/stdc++.h>

using namespace std;
int mmax = -1e9-5, mmin = 1e9+5, a, n;
int main(){
	cin >> n;
	while (n--){
		cin >> a;
		mmax = max(mmax,a);
		mmin = min(mmin,a);
	}
	cout << mmax-mmin;
	
	return 0;
}
