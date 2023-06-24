#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
//#include <algorithm>
//functional
//limit
//numeric_limits

using namespace std;


int main() {
	//ifstream fi("input.inp");
	//ofstream fo("output.out");
	
	long long int a, b;
	cin >> a >> b;
	a = abs(a);
	b = abs(b);
	
	if ((a==0)||(b==0)){
		if (a==0) cout << b; else cout << a;
		return 0;
	}
	
	/*while ((a!=0)&&(b!=0)){
		if (a>b) a = a%b;
		if (a<b) b = b%a;
		//cout << a << " "  << b << endl;
	}*/
	cout << __gcd(a,b);
	
	//fi.close();
	//fo.close();
	return 0;
}
