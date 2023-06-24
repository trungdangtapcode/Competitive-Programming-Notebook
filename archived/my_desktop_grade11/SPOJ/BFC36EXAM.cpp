#include <bits/stdc++.h>

using namespace std;

int a, b, c, n, d;
int main(){
	cin >> a >> b >> c >> n;
	d = n - (a + b - c);
	cout << (d>0&&a>=c&&b>=c?d:-1);
	
	return 0;
}
