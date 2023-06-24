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

long long int f(long int x){
	return (x*(x-1)/2);
}

int main() {
	//ifstream fi("input.inp");
	//ofstream fo("output.out");
	
	
	long int n;
	int* a = new int[1000000];
	memset(a,1,sizeof(a));
	cin >> n;
	for (long int i= 0; i <n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i = 0; i< n; i++) cout << a[i]<<" "; cout << endl;
	long long int result = 0;
	long int index = 0;
	while (index<n){
		long int last_index = upper_bound(a,a+n,a[index])-a;
		result += f((last_index-1)-index+1);
		cout << index << " " << last_index << " ->  "<< f((last_index-1)-index+1)<< endl;
		index = last_index;
	}
	cout << result;
	
	
	//fi.close();
	//fo.close();
	return 0;
}
