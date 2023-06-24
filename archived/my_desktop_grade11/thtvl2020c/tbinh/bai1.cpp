#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>

using namespace std;


int main() {
	ifstream fi("input.inp");
	ofstream fo("output.out");
	
	unsigned long long int n, x, y;
	cin >> n >> x >> y;
	cout << x << endl;
	if (x < y){
		x = x + y;
		y = x - y;
		x = x - y;
	}
	//cout << x << " " << y;
	
	unsigned long long int t, t1, t2, z;
	
	t1 = (n)/(x+y);
	t2 = (n)/(x+y);
	n %= x+y;
	
	if (n>=x) {
		t1 += n/x;
		n %= x;
	}
	if (n>=y) {
		t2 += n/y;
		n %= y;
	}
	z = n;
	t = t1 + t2;
	cout << t  << " "<< t1 << " "<< t2 << " "<< z << endl;
	
	fi.close();
	fo.close();
	return 0;
}
