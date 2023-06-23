#include<bits/stdc++.h>

using namespace std;
long double a, b, r, n, pi;
int main(){
	pi = atan(1)*4;
	cin >> a >> b >> r >> n;
	n *= 100000;
	cout << (int)(n/(2*r*pi)*a/b);
	
	return 0;
}
