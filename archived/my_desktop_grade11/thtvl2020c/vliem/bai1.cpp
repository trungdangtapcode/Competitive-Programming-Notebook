#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;


int main() {
	ifstream fi("input.inp");
	ofstream fo("output.out");
	
	int n,k,m;
	cin >> n >> k >> m;
	
	if ((m+n) % 2 == 1) {
		cout << 0;
		return 0;
	}
	int V = (n-m)/2;
	int X = (n+m)/2;
	int T = k*V+2*k*X/3;
	
	cout << V << " " << X << " " << T << endl;
	
	
	fi.close();
	fo.close();
	return 0;
}
