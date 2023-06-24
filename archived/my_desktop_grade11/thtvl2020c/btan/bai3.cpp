#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>

using namespace std;

bool check(int x){
	int sum =0;
	for (int i = 1; i <= sqrt(x); i++){
		if (x%i == 0) sum += i + x/i;
		if (i*i == x) sum -= sqrt(x);
	}
	return x == sum-x;
}

int main() {
	ifstream fi("input.inp");
	ofstream fo("output.out");
	
	int N;
	cin >> N;
	
	if (!(check(N))){
		cout << 0;
		return 0;	
	}
	
	bool ch = false;	
	for (int i = 1; i <= sqrt(N); i++){
		if (N%i == 0){
			if (ch) cout << " + ";
			cout << i;
			ch = true;	
		}
	}
	for (int i = sqrt(N); i > 1; i--){
		if (N%i == 0){
			if (ch) cout << " + ";
			if (i*i!=N) cout << N/i;
			ch = true;	
		}
	}
	
	
	
		
	fi.close();
	fo.close();
	return 0;
}
