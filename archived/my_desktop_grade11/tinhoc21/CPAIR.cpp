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
	long int n, s;
	long int a[200000];
	memset(a,0,sizeof(a));
	long int tanso[2000];
	memset(tanso,0,sizeof(tanso));
	cin >> n >> s;
	for (long int i = 0; i < n; i++){
		cin >> a[i];
		tanso[a[i]]++;
	}
	long int result = 0;
	for (long int i = 0; i < n; i++) if ((s-a[i])>=0){
		result += tanso[s-a[i]];
	}
	for (long int i = 0; i < n; i++) if (2*a[i] == s) result--; 
	cout << (long int)(result/2);
	
	return 0;
}
