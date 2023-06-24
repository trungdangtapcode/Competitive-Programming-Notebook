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
	long int S;
	int a[10000];
	long int sum[10000];
	sum[0] = 0;
	cin >> n >> S;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
		
	bool check = false;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (sum[j]-sum[i-1] == S){
				check = true;
			}
		}
	}
	
	if (check) cout << "YES"; 
		else cout << "NO";
	
	//fi.close();
	//fo.close();
	return 0;
}
