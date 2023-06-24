#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	cin >> n;
	int base10 = 1;
	while (base10<=n) base10 *= 10;
	--base10;
	(n += 8) /= 9;
	base10 /= 9;
	cout << 1ll*(n+base10)*(base10-n+1)/2*9;

	
	return 0;
}
