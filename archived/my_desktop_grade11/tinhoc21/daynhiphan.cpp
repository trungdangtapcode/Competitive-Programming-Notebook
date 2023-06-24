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

void deQuy(int a[],int n, int k){
	if (k>n){
		for (int i = 1; i <= n; i++){
			cout << a[i];
		}
		cout << endl;
	} else {
		a[k] = 0;
		deQuy(a,n,k+1);
		a[k] = 1;
		deQuy(a,n,k+1);
	}
}

int main() {
	int n;
	int a[100];
	cin >> n;
	deQuy(a,n,1);
	
	
	//cout << result;
	
	return 0;
}
