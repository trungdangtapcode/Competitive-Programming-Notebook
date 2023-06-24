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
	
	//int[] thuong = new int[26];
	//int[] hoa = new int[26];
	int thuong[26];
	int hoa[26];
	
	memset(thuong, 0, 26*4);
	memset(hoa, 0, 26*4);
	
	string s;
	cin >> s;
	
	for (int i = 0; i < s.length(); i++){
		if ((int(s[i]) >= int('a')) && (int(s[i]) <= int('z'))) thuong[int(s[i]) - int('a')]++;
		if ((int(s[i]) >= int('A')) && (int(s[i]) <= int('Z'))) hoa[int(s[i]) - int('A')]++;
	}
	
	
	//return 0;
	for (int i = int('z')-int('a'); i >= 0 ; i--){
		for (int j = 0; j < hoa[i]; j++) cout << char(i+int('A'));
		for (int j = 0; j < thuong[i]; j++) cout << char(i+int('a'));
	}
	cout << endl;
	
	fi.close();
	fo.close();
	return 0;
}
