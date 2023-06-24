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
	long int a[100001];
	long int div[3];
	memset(div,0,sizeof(div));
	cin >> n;
	for (long int i = 0; i < n; i++){
		cin >> a[i];
		div[a[i]%3]++;
	}
	long long int result = 0;
	for (long int i = 0; i < n; i++){
		if (a[i]%3 == 1) result+= div[2]; 
		if (a[i]%3 == 2) result+= div[1];
		if (a[i]%3 == 0) result+= div[0]-1;
	}
	result/= 2;
	cout << result;
	
	return 0;
}
