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
	int cs = 0;
	long long int sum = 0;
	cin >> n;
	while (n!=0){
		sum += n%10;
		cs++;
		n /= 10;
	}
	cout << cs << " " << sum;
	
	//fi.close();
	//fo.close();
	return 0;
}
