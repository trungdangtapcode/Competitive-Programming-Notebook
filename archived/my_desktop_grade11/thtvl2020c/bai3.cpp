#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

bool check(int x){
	int sa = 0, sb = 0;
	//x = b ab ab ab ab

	
	while (x>=10){
		sb += x%10;
		x /= 10;
		sa += x%10;
		x /= 10;
	}
	sb += x%10;
	x /= 10;
	return (sa == sb);
};

int main() {
	ifstream fi("input.inp");
	ofstream fo("output.out");
	
	int m;
	cin >> m;
	
	while (true){
		if (check(m)){
			cout << m;
			return 0;
		}
		m--;
	}
	
	
	fi.close();
	fo.close();
	return 0;
}
