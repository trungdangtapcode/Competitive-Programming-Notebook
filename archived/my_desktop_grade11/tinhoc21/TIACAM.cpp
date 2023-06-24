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
	
	long int n, k;
	long long int* a = new long long int[1000000];
	long long int* b = new long long int[1000000];
	cin >> n >> k;
	for (long int i = 0; i < n;i++) cin >> a[i];
	for (long int i = 0; i < k;i++) cin >> b[i];
	
	sort(a,a+n);
	for (long int i = 0; i < k; i++){
		cout << n-(lower_bound(a,a+n,b[i])-a) << " ";
	}
	
	//fi.close();
	//fo.close();
	return 0;
}
