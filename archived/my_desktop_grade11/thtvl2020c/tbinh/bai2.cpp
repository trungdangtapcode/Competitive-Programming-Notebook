#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>

using namespace std;

bool check(unsigned long long int x){
	long long int p = 1, s = 0;
	while (x>0){
		p *= x%10;
		s += x%10;
		x /= 10;
	}
	return (p == s);
}

int main() {
	ifstream fi("input.inp");
	ofstream fo("output.out");
	
	long long int n;
	
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (true){
		if (check(n)){
			cout << n << endl;
			return 0;
		}
		n--;
	}
	fi.close();
	fo.close();
	return 0;
}
