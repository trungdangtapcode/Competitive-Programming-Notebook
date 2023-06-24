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
	
	long int n;
	long int* a = new long int[1000000];
	long int* b = new long int[1000000];
	cin >> n;
	for (long int i= 0; i < n;i++){
		cin >> a[i];
	}
	for (long int i = 0; i< n; i++){
		cin >> b[i];
	}
	long int max_a =  *max_element(a , a + n);
	long int min_a =  *min_element(a , a + n);
	long int max_b =  *max_element(b , b + n);
	long int min_b =  *min_element(b , b + n);
	long int r1 = abs(max_a - min_b);
	long int r2 = abs(max_b-min_a);
	cout << max(r1,r2);
	
	//fi.close();
	//fo.close();
	return 0;
}
