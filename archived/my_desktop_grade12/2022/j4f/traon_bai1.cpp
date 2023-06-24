#include<bits/stdc++.h>

using namespace std;

unsigned long long n, m, u;

int main(){
	cin >> n >> m;
	u = __gcd(n, m);
	n /= u;
	m /= u;
	cout << n << " " << m;
	
	return 0;
}
