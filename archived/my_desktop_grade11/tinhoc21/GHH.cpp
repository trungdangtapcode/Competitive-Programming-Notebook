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


bool check(long long int x){
	bool ch = (x==(long long int)sqrt(x)*(long long int)sqrt(x));
	long long int sum = 0;
	for (long long int i = 1; i <= sqrt(x);i++){
		if (x%i == 0){
			sum += i + (x/i);
		}
	}
	if (ch){
		sum -= sqrt(x);
	}
	return (2*x<=sum);
}

int main() {
	int k;
	long long int a[200];
	cin >> k;
	for (int i = 0; i<k; i++){
		cin >> a[i];
	}
	
	int b[200];
	for (int i = 0; i <k;i++){
		cin >> b[i];	
	}
	
	for (int i = 0; i<k; i++) {
		//cout <<a[i] << " - "<< check(a[i]) << " " << b[i] << "     " << (check(a[i]) == b[i])<<endl;
		cout <<a[i] << endl;
	}
	return 0;
}
