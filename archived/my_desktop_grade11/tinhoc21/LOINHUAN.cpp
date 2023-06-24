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
	long int a[100005];
	long long int sum[100005];
	cin >> n;
	sum[0] = 0;
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
	sort(sum,sum+n+1);
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
	long int result;
	return 0;
}
