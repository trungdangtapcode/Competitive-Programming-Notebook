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
	int n;
	long int s;
	long long int a[2000];
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int count = 0;
	for (int i = 0; i < n-1; i++) {
		if (a[i]+a[i+1] == s) count++;
	}
	cout << count;

	//cout << result;
	
	return 0;
}
