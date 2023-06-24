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
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int a , b;
	cin >> a >> b;
	sort(arr+a, arr + b+1);
	
	for (int i = 0; i < 10; ++i){
		if (i == a) cout << "(";
        cout << arr[i] << " ";
		if (i == b) cout << ")";
	}
	return 0;
}
