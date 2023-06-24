#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>


using namespace std;


int main() {
	
	double a, b, c, p, s;
	cin >> a >> b >> c;
	p = a + b + c;
	s = sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c))/4;
	cout << "Chu vi tam giac = " << p << endl;
	cout << "Dien tich tam giac = " << s << endl;
	return 0;
}
