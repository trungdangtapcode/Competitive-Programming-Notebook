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
	long long int a[10000], sum[10000];
	cin >> n;
	sum[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	long long int result = -1e9;
	for (int i = 1; i <= n; i++){
		long long int max = -1e9;
		for (int j = i; j <= n; j++){
			max = (max>sum[j]-sum[i-1])?max:(sum[j]-sum[i-1]);
		}
		result = (result>max)?result:max;
	}
	cout << result;
	
	//fi.close();
	//fo.close();
	return 0;
}
