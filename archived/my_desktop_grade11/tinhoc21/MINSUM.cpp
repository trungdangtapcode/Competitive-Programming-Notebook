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
	
	long long int G, L;
	cin >> G >> L;
	
	if (L%G != 0){
		cout << -1;
		return 0;
	}
	long long int result = 1e10;
	long long int M = L/G;
	for (long long int i = 1; i <= sqrt(M); i++){
		if (M%i == 0) result = min(result,i+M/i);
	}
	cout << G*result;
	
	//fi.close();
	//fo.close();
	return 0;
}
