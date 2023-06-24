#include <bits/stdc++.h>

using namespace std;
double x1, y1, x2, y2, x3, y3, r, p;
double a, b, c, d, alpha, pcut, myPI = 4*atan(1);

int main(){
	
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> p;
	if (x1==x2&&y1==y2) {
		cout << "NO";
		return 0;
	}
	a = y1 - y2;
	b = - x1 + x2;
	c = -a*x1 - b*y1;
	//a = (y2-y1)/(x1*y2-x2*y1);
	//b = (x1-x2)/(x1*y2-x2*y1);
	//d: ax + by - 1 = 0;
	d = abs(a*x3+b*y3+c)/sqrt(a*a+b*b);
	if (d >= r - 1e-15){ //
		cout << "NO";
		return 0;
	}
	alpha = 2*acos(d/r);
	pcut = (alpha*r*r/2-sin(alpha)*r*r/2)/(myPI*r*r)*100;
	cout << (abs(pcut-p)<=5?"YES":"NO");
	
	return 0;
}
