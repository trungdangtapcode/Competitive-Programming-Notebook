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
	long long int a[100005],b[100005];
	cin >> n;
	for (long int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (long int i = 0; i < n; i++){
		cin >> b[i];
	}
	sort(b,b+n);
	//for (long int i = 1; i <=n n; i++) cout << b[i] << " "; cout << endl;
	long long int result = 1e10;
	for (long int i = 0; i < n; i++){
		//tham lam 1: a + b <= +S
		long int k = lower_bound(b,b+n,-a[i])-b;
		//cout << k<< " "<< b[k]<< endl;
		result = min(result,min(abs(b[max(k-1,(long int)0)]+a[i]),abs(b[k]+a[i])));
	}
	cout << result;
	return 0;
}
