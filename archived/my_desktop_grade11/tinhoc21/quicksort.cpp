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
	long int n;
	long long int a[100001];
	cin >> n;
	for (long int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for (long int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	
	//cout << result;
	
	return 0;
}
