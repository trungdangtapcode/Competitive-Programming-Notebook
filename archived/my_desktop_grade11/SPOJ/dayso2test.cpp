#include <stdio.h>
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
long int n;
long long int sum[100005], myMin[100005];



int main() {
	//fail :(( luc bo bien a[] la bi loi
	cin >> n;
	sum[0] = 0;
	for (long int i = 1; i <= n; i++){
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	for (long int i = n+1; i <= 2*n; i++){
		sum[i] = sum[i-1] + sum[n];
	}
	myMin[n] = sum[n];
	for (long int i = n; i > 0; i--){
		myMin[i-1] = min(myMin[i],sum[i-1]);
	}
	myMin[n] = sum[n];
	for (long int i = 1; i <= n; i++){ //can't touch 2n
		myMin[i+n] = min(myMin[i+n-1],sum[i+n]);
	}
	long int result = 0;
	for (long int i = 1; i <= n; i++) result+=(sum[i-1]<min(myMin[i],myMin[n+i-1]));
	
	cout << result;
	//cout << result;
	
	
	
	return 0;
}
