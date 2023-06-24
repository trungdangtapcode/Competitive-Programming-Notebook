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
	long long int *a = new long long int[100001];
	long long int *sum = new long long int[100001];
	long long int *Rmax = new long long int[100001]; //max cua sum
	cin >> n;
	sum[0] = 0;
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	Rmax[n+1] = sum[n];
	for (long int i = n; i > 0; i--){
		Rmax[i] = max(Rmax[i+1],sum[i]);
	}
	long long int result = -1e16;
	for (long int i = 1; i <= n; i++){
		result = max(result,Rmax[i]-sum[i-1]);
	}
	cout << result;
	
	
	
	return 0;
}
