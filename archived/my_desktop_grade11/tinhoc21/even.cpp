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
	
	long long int n;
	cin >> n;
	if (n%2 == 1){
		long long int x = (n+1)/2;
		cout << x*x;
	} else {
		long long int x = n/2;
		cout << x*x;
	}
	
	//fi.close();
	//fo.close();
	return 0;
}
