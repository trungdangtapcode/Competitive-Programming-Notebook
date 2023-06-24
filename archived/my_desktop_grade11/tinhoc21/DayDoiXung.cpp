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
	long long int *a = new long long[2005];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int result = -1;
	for (int i = 0; i < n; i++){
		int next = i, pre = i;
		int x = -1;
		while ((pre>=0&&next<n)&&(a[pre]==a[next])){
			x+= 2;
			pre--;
			next++;
		}
		result = max(result,x);
		next = i+1; pre = i;
		x = 0;
		while ((pre>=0&&next<n)&&(a[pre]==a[next])){
			x+= 2;
			pre--;
			next++;
		}
		result = max(result,x);
	}
	cout << result;
	//cout << result;
	
	
	
	return 0;
}
