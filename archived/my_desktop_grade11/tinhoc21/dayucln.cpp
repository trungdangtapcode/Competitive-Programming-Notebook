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

void solve(){
	long int n;
	long long int* a = new long long int[200000];
	cin >> n;
	for (long int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << a[0] << " "; //lcm(1,a[0]) smallest mean bcnn
	for (long int i = 1; i < n; i++){
		cout << a[i-1]*a[i]/__gcd(a[i-1],a[i]) << " ";
	}
	cout << a[n-1] << endl; //lcm(a[n-1],1) 1 is the smallest one
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		solve();
	}
	return 0;
}
