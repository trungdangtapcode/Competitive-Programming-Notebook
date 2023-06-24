#include<bits/stdc++.h>

using namespace std;
int n, m, base10 = 1;
int main(){
	cin >> n >> m;
	while (10ll*base10<=n) base10 *= 10;
	(base10 += m-1) /= m;
	n /= m;
	cout << 1ll*(n-base10+1)*(n+base10)/2*m << "\n";
	
	
	return 0;
}
