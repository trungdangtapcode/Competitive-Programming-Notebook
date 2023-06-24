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
	long int n;
	long int *a = new long int[100001];
	long int *theMin = new long int[100001];
	long long int *lsum = new long long int[100001];
	cin >> n;
	for (long int i =0; i < n; i++){
		cin >> a[i];
	}
	lsum[n] = 0;
	theMin[n] = 1e5;
	for (long int i = n-1; i >= 0; i--){
		theMin[i] = min(theMin[i+1],a[i]);
		lsum[i] = lsum[i+1]+a[i]; 
	}
	//for (long int i =0; i < n; i++) cout << lsum[i] << " ";  cout << endl;
	//for (long int i =0; i < n; i++) cout << theMin[i] << " ";  cout << endl;
	long long int result_tu = -1e6; long long int result_mau = 1; //thu -1e6 doi thanh long long int thu tai so kha lon -> OMG AC CMNR
	for (long int i =0; i < n-2; i++){ //k = i+1 <= n-2
		//double x = (lsum[i+1]-theMin[i+1])/(n-i-1);
		//result = max(result,x);
		if ((n-(i+1)-1)*(result_tu)<(result_mau)*(lsum[i+1]-theMin[i+1])){
			result_tu = lsum[i+1]-theMin[i+1];
			result_mau = n-(i+1)-1;
		}
	}
	//cout << result_tu << " " << result_mau << endl;
	for (long int i =0; i < n-2; i++){ //-1 thu coi
		//double x = (lsum[i+1]-theMin[i+1])/(n-i-1);
		//if (x == result){
		if ((n-(i+1)-1)*(result_tu)==(result_mau)*(lsum[i+1]-theMin[i+1])){
			cout << i+1<< " ";
		}
	}
	/*double result = -1e4;
	for (long int i =0; i < n-2; i++){ //k = i+1 <= n-2
		double x = (lsum[i+1]-theMin[i+1])/(n-i-2);
		result = max(result,x);
	}
	for (long int i =0; i < n-2; i++){
		double x = (lsum[i+1]-theMin[i+1])/(n-i-2);
		if (x == result){
			cout << i+1<< " ";
		}
	}*/
	return 0;
}
