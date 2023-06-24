#include <stdio.h>
#include <conio.h>
#include <iostream> 
#include <math.h> 
#include <algorithm>

using namespace std;
int main()
{
	long int a, b; //khai bao
	cin >> a >> b; //nhap vao
	long int ucln = __gcd(a,b); //tim gcd
	a = (long int)(a/ucln); //toi gian a
	b = (long int)(b/ucln); //toi gian b
	cout << a <<"/"<< b << endl; //in ra man hinh
	
	//cout << a/b << endl;
	long int mau = b;
	while (mau % 2 == 0) mau = (long int)(mau / 2); //khu toan bo uoc 2
	while (mau % 5 == 0) mau = (long int)(mau / 5); //khu toan bo uoc 5
	if (mau == 1) cout << "Huu han" << endl; //mau chi co uoc 2 va 5
		else cout << "Vo han tuan hoan" << endl; //mau con uoc khac
	
	return 0;
}
