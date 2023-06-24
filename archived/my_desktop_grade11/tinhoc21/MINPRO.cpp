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
	//if (x>b){ //mistaked from a,x and b,y. then still find max
	if (n > b - y){
		n -= b - y;
		b = y;
		if (n > a - x){
			n -= a -x;
			a = x;
		} else {
			a -= n;
		}
	} else {
		b -= n;
	}
	cout << a*b;
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
