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
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n ; i++){
		double x = sqrt(i*i*i-2);
		int y = sqrt(i*i*i-2);
		if (x == y){
			cout << INT_MAX << " " << i << endl;
		}
	}
	fi.close();
	fo.close();
	return 0;
}
