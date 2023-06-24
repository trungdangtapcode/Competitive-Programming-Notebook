#include<bits/stdc++.h>

using namespace std;
unsigned long long n, m, a, b,c;
int main(){
	cin >> n >> m;
	b = n/(3*m+1);
	a = m*b;
	c = 2*m*b;
	cout << a << " " << b << " " << c << " " << n-a-b-c << "\n";
	
	return 0;
}
