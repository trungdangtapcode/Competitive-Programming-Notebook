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
long int a[100005];
long long int sum[100005], myMin[100005];



int main() {
	cin >> n;
	sum[0] = 0;
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	for (long int i = n+1; i <= 2*n; i++){
		sum[i] = sum[i-1] + a[i-n];
	}
	// 1 2 3 ... j ... n [minL] | [minR] n+1 ... n+j ... 2n-1 2n
	//O(2n) => O(n) thay thi O(n^2) min[i->j] = min(min[i->|],min[|->j]) (DK: i<|<j=i+n), | la vach ngan chu khong phai index
	myMin[n] = sum[n];
	for (long int i = n; i >= 1; i--){
		myMin[i-1] = min(myMin[i],sum[i-1]);
	}
	//myMin[n+1] = sum[n+1];
	for (long int i = n+1; i <= 2*n; i++){ //can't touch 2n
		myMin[i] = min(myMin[i-1],sum[i]);
	}
	long int result = 0;
	for (long int i = 1; i <= n; i++) if (sum[i-1]<min(myMin[i],myMin[n+i-1])) result++;
	
	cout << result;
	//cout << result;
	
	
	
	return 0;
}
