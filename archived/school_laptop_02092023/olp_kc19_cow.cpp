#include<bits/stdc++.h>

using namespace std;
int n;
long long a, b, x, y, r;
long double mmin = 1e12;
int main(){
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++){
		cin >> x >> y >> r;
		mmin = min(mmin,(long double)sqrt((a-x)*(a-x)+(b-y)*(b-y))-r);
	}
	if (mmin-(int)mmin<1e-9) cout << (int)mmin-1;
	else cout << (int)mmin;
	
	return 0;
}
