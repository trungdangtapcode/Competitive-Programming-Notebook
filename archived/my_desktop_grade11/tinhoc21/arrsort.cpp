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
	double a[2000];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i = 0; i < n; i++){
		cout << fixed << setprecision(2) << a[i] << " ";
	}
	cout << endl;
	for (int i = n-1; i >= 0; i--){
		cout << fixed << setprecision(2) << a[i] << " ";
	}
	//cout << count;

	//cout << result;
	
	return 0;
}
