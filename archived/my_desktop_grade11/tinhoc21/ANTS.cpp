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
	long long int k;
	long int n;
	cin >> n >> k;
	unsigned long long int result = 0;
	for (long int i = 0; i < n; i++){
		long long int x;
		cin >> x;
		if (x<0)
			result = max(result,(unsigned long long int)abs(x));
		if (x>0)
			result = max(result,(unsigned long long int)(k-abs(x)));
	}
	cout << result;
	
	return 0;
}
