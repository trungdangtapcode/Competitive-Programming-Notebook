#include <bits/stdc++.h>

using namespace std;

int n, mmax, mmin; //-1e6,1e6->0,0

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		mmax = max(mmax,a);
		mmin = min(mmin,a);
	}
	cout << 2*(mmax-mmin);
	
	return 0;
}
