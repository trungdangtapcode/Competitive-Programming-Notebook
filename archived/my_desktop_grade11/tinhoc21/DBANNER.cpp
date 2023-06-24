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
	long long int a[2000];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	long long int result = 0;
	for (int i = 0; i < n; i++){
		int r = i, l = i;
		while (r < n && a[r] >= a[i]) r++;
		r--; //du am cai cuoi :v
		while (l >= 0 && a[l] >= a[i]) l--;
		l++;
		//cout << l << " " << r << " -> " << (r-l+1)*a[i] << endl;
		result = max(result,(r-l+1)*a[i]);
	}
	cout << result;
	
	//fi.close();
	//fo.close();
	return 0;
}
