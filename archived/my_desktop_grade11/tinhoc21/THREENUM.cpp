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
	long long int* a = new long long int[200000];
	long long int* maxL = new long long int[200000];
	long long int* maxR = new long long int[200000];
	
	cin >> n;
	for (long int i = 0; i <= n+1; i++){ //vo duyen
		maxL[i] = 0;
		maxR[i] = 0;
	}
	maxL[0] = -1e10;
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		maxL[i] = max(maxL[i-1],a[i]);
	}
	maxR[n+1] = -1e10;
	for (long int i = n; i >= 1; i--) maxR[i] = max(maxR[i+1],a[i]);
	
	long long int result = -1e10;
	for (long int i = 1; i <= n; i++){
		result = max(result,2*maxL[i-1]-3*a[i]+5*maxR[i+1]);
	}
	cout << result;
	
	
	//fi.close();
	//fo.close();
	return 0;
}
