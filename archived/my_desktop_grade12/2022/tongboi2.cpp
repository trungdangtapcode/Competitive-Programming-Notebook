#include<bits/stdc++.h>

using namespace std;
long long r, l, k;
int main(){
	cin >> l >> r >> k;
	l = (l+k-1)/k;
	r = r/k;
	cout << (l+r)*(r-l+1)/2*k;
	
	
	return 0;
}
