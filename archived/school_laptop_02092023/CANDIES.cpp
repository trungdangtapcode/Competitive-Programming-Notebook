#include<bits/stdc++.h>

using namespace std;
int n, a, b, c;
int main(){
	cin >> n >> a >> b;
	c = (2*b/n)*n;
	if (c<=2*a) cout << a << " " << a;
	else if (c>=a+b) cout << b << " " << c-b;
	else cout << c-a << " " << a;
	
	return 0;
}
