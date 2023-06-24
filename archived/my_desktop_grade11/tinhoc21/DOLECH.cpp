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
	
	//input
	long int n;
	//-vector <long int> a;
	int* a = new int[1000000];
	int* max = new int[1000000]; //i -> n
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	//ready
	max[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i--){
		max[i] = (max[i+1]>a[i])?max[i+1]:a[i];
	}
	//-for (int i = 0; i < n; i++) cout << max[i]<< endl;
	
	//solve
	long int result = 0;
	for (int i = 0; i <n; i++){
		result = (result>(max[i]-a[i]))?result:(max[i]-a[i]);
	}
	cout << result;
	
	
	//sort(a.begin(),a.end());
	//for(int i = 0; i < n; i++){
	//	cout << *(a.end()-1)-*a.begin()<< endl;
	//}
	
	//fi.close();
	//fo.close();
	return 0;
}
