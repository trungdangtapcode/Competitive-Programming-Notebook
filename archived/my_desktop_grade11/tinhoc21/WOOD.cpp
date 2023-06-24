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
	long long int s;
	long long int* a = new long long int[200000];
	long long int* sum = new long long int[200000];
	cin >> n >> s;
	sum[0] = 0;
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	//for (long int i = 1; i <= n; i++) cout << sum[i] << " "; cout << endl;
	
	long long int result = 1e10;
	for (long int i = 1; i <= n; i++){
		//cout << i<< " "<< (lower_bound(sum,sum+n+1,s+sum[i-1])-sum)-(long long int)i+1 << endl;
		if ((lower_bound(sum,sum+n+1,s+sum[i-1])-sum)<= n)
			result = min(result,(lower_bound(sum,sum+n+1,s+sum[i-1])-sum)-(long long int)i+1);
	}
	cout << result << endl;
	
	
	
	return 0;
}
