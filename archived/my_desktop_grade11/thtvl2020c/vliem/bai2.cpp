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
	
	int n, m;
	cin >> n >> m;
	
	int case10 = 1;
	for (int i = 1; i < n; i++){
		case10 *= 10;
	};
	
	int sum = 0;
	bool ch = false;
	for (int i = case10; i < case10*10; i++){
		if ((i % n) == 0) {	
			int x = i;
			if (m<n) for (int j = 0; j < n-m; j++) x /= 10;
				else for (int j = 0; j < m-n; j++) x *= 10;
			if (ch) {
				cout << " + ";
			}
			ch = true;
			cout << x;
			sum += x;
		}
	}
	
	cout << " = " << sum << endl;
	fi.close();
	fo.close();
	return 0;
}
