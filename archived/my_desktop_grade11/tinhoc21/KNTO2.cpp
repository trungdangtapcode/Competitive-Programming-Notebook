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
		long long int n;
		cin >> n;
		long long int n0 = n;
		
		long long int i = 2;
		long long int prime = 0;
		long long int result = 1; //1 chinh la mot uoc dau tien khoi can cong  (nhat la khuc cuoi)
		//i^m la uoc. theo cong thuc la bang product of (m + 1)
		while (n != 1 && i*i<=n0){ //fuck the 1 and the N //or just i*i <= n
			if (n%i == 0) prime++;
			long long int m = 0;
			while (n%i == 0){
				n /= i;
				m++;
			}
			result *= (m+1);
			i++;
		}
		//finally, n da tro thanh so nguyen to hoac 1 :v
		//1 thi no cung vay tinh la uoc cung nhu ko, con so nguyen to bi tru me roi
		if (n != 1) {
			result *=2;
			prime++; //that is, so nguyen to!
		}
		result = result - prime; //tru nhung lan tim thay mot i dat biet (so nguyen to trong i^m)
		cout << result;
		return 0;
	}
