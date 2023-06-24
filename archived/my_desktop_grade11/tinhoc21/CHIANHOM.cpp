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
	long long int* a = new long long int[1000000];
	long long int* sum = new long long int[1000000]; 
	cin >> n;
	sum[0] = 0;
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	
	//for (int i = 1; i <= n; i++) cout << sum[i] << " "; cout << endl;
	
	long long int min = 1e10;
	long int m = 0;
	for (long int i = 1; i < n; i++){
		//cout << (sum[n]-sum[i]) << " " << (sum[i])  << " delta=" << abs((sum[n]-sum[i])-(sum[i]))<< endl; 
		if (abs((sum[n]-sum[i])-(sum[i]))<=min){
			m = i;
			min = abs((sum[n]-sum[i])-(sum[i]));
		}
	}
	cout << m;
	
	//fi.close();
	//fo.close();
	return 0;
}
