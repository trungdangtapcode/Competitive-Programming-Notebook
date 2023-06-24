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
	
	int m,n;
	cin >> n >> m;
	
	int p = 2;
	int count = 0;
	for (int i = 1; i <= n; i++){
		if ((p%m) == 0) count++;
		p += i;
	}
	cout << count << endl;
	
	fi.close();
	fo.close();
	return 0;
}
