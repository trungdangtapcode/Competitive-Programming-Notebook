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
	
	int n, s;
	cin >> n;
	s = 1;
	int a = sqrt(n);
	cout << a << endl;
	while (s*s<=n){
		cout << s*s << " ";
		s++;
	}
	
	//fi.close();
	//fo.close();
	return 0;
}
