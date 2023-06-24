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
	for (long long int i = 2; i <= sqrt(n); i++){
		if (n%i==0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	
	//fi.close();
	//fo.close();
	return 0;
}
