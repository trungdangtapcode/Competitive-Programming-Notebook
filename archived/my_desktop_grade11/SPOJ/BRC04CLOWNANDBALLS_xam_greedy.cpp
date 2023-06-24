#include <bits/stdc++.h>

using namespace std;
int n;
long long int s, a, mmax;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		s = s^a;
		mmax = max(mmax,mmax^a);
	}
	cout << mmax + (mmax^s);
	
	return 0;
}
