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
int n, m, k;
string s, s0;

int check(){
	int myMin = 1e4;
	for (int i = 0; i < n; i++){
		int x = 0;
		for (int j = i; j < i+m; j++) 
			if (s[j]!=s0[j-i]) x++;
		myMin = min(myMin,x);
	}
	return myMin;
}

int main() {
	cin >> n >> m >> k;
	cin >> s;
	s = s + s;
	int result = 1e4;
	for (int i = 0; i < k; i++){
		cin >> s0;
		result = min(result,check());
	}
	cout << result;
	//cout << result;
	
	
	
	return 0;
}
