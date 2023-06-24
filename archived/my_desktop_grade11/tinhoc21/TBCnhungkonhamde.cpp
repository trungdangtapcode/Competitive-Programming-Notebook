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

void solve(){
	int n;
	long long int a[2000];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	long int result = 0;
	for (int i = 0; i < n; i++){
		for (int j = i+2; j < n; j++){
			if ((a[i]+a[j]) % 2 == 0)
			if (binary_search(a+i+1,a+j,(a[i]+a[j])/2)) 
				result+= (upper_bound(a+i+1,a+j,(a[i]+a[j])/2)-a)-1-(lower_bound(a+i+1,a+j,(a[i]+a[j])/2)-a)+1;
		}
	}
	
	cout << result << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i= 0; i < T; i++){
		solve();
	}
	
	return 0;
}
