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
	long long int a, b, x, y, n;
	cin >> a >> b >> x >> y >> n;
	if (a<b) {
		swap(a,b);
		swap(x,y);
	}
	long long int a0 = a, b0 = b, x0 = x, y0 = y, n0 = n;
	
	if (n <= b - y){
		cout << a*(b-n) << endl;
		return;
	}
	long long int result = 1e10;
	//dung tham lam, ngoi chung minh ca cuoi, ngoi tim gtln bat 2 khi a > 0 haha
	//tham lam 1: don a
	if (n > a - x){
		n -= a - x;
		a = x;
		if (n > b - y){
			n -= b - y;
			b = y;
		} else {
			b -= n;
		}
	} else {
		a -= n;
	}
	result = a*b;
	//tham lam 2: don b
	a = a0; b = b0; x = x0; y = y0; n = n0;
	if (n > b - y){
		n -= b - y;
		b = y;
		if (n > a - x){
			n -= a - x;
			a = x;
		} else {
			a -= n;
		}
	} else {
		b -= n;
	}
	//cout << result << " and " << a*b;
	result = min(result,a*b);
	cout << result << endl;
}

int main() {
	//ifstream fi("input.inp");
	//ofstream fo("output.out");
	
	long int T;
	cin >> T;
	for (long int i = 0; i < T; i++){
		solve();	
	}
	
	//fi.close();
	//fo.close();
	return 0;
}
