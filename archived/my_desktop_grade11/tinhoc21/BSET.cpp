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
	
	long int n, m;
	long int a[200000];
	long int b[200000];
	cin >> n >> m;
	for (long int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (long int i = 0; i < m; i++){
		cin >> b[i];
	}
	set<long int> set_a(a,a+n);
	sort(b,b+m);
	//for (long int i = 0; i < m; i++) cout << b[i] << " "; cout << endl;
	long int trunglap = 0;
	//for (long int i = 0; i < set_a.size(); i++){
	for (long int it: set_a){
		long int lower = lower_bound(b,b+m,it)-b;
		long int upper = upper_bound(b,b+m,it)-b;
		//cout << binary_search(b,b+m,a[i]) << " " << lower << " " << upper << endl;
		if (binary_search(b,b+m,it)) trunglap += (upper-1)-lower+1; //binary cho chac tranh overflow mang
	}
	cout << n + m - trunglap << " " << trunglap;
	
	return 0;
}
