#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>

using namespace std;

bool check(int x0){
	int x = x0;
	int sum = 0;
	while (x>0){
		sum += x % 10;
		x /= 10;
	}
	return (sum*sum == x0);
}

int main() {
	ifstream fi("input.inp");
	ofstream fo("output.out");
	
	int N;
	cin >> N;
	
	for (int i = 0; i<N; i++){
		if (check(i)){
			cout << i << endl;
		}
	}
	
	
	fi.close();
	fo.close();
	return 0;
}
