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
	
	int n;
	long int a[10000], sum[10000], summax[10000];
	cin >> n;
	sum[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	summax[n+1] = -1e9;
	for (int i = n; i >= 0; i--){
		summax[i] = max(summax[i+1],sum[i]);
	}
	//for (int i = 1; i <= n; i++) cout << summax[i] << endl;
	long int result = -1e9;
	for (int i = 1; i <= n; i++){
		result = max(summax[i]-sum[i-1],result);
	}
	cout << result;
	
	//fi.close();
	//fo.close();
	return 0;
}
