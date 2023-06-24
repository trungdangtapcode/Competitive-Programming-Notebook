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
	int n;
	long long int a[2000],b[2000];
	//long long int* a = new long long int[]
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	copy(begin(a),end(a),begin(b));
	for (int i = 0; i < n; i++){
		sort(b,b+i);
		sort(b+i+1,b+n);
		
	}
	
	cout << result;
	
	return 0;
}
