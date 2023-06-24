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

int main() {
	long int n, q;
	long int *sum = new long int[1000001];
	cin >> n >> q;
	string s0,s;
	cin >> s0;
	s = ' ' + s0;
	sum[0] = 0;
	for (long int i = 1; i <=n; i++){
		int x = 0;
		if (s[i]=='(') x = 1; else x = -1;
		//cout << x << endl;
		sum[i] = sum[i-1] + x;
		//cout << (long int)(s[i]=='(')?(2):(3) << endl;
	}
	//for (long int i = 0; i <=n; i++){
	//	cout << sum[i] << " " ;
	//}
	for (long long int i = 0; i < q; i++){
		long long int x;
		cin >> x;
		if (s[x]=='('){
			s[x] = ')';
			for (long int j = x; j <= n; j++){
				sum[j] -= 2;
			}
			long long j = 1;
			bool ch = true;
			while (ch){
				if (s[j] ==')'){
					ch = false;
					cout << j << " ";
					s[j] = '(';
				}
				j++;
			}
			for (long int k = j; k <= n; k++){
				sum[j] += 2;
			}
		}
		//===
		else if (s[x]==')'){
			s[x] = '(';
			for (long int j = x; j <= n; j++){
				sum[j] += 2;
			}
			bool xetMang[1000001];
			xetMang[n+1] = true;
			for (long int j = n; j > 0; j--){
				if (xetMang[j+1]){
					if (sum[j]<2) xetMang[j] = false; else xetMang[j] = true;
				} else xetMang[j] = false;
			}
			long long j = 1;
			bool ch = true;
			while (ch){
				if (s[j] =='(' && xetMang[j]){
					ch = false;
					cout << j << " ";
					s[j] = ')';
				}
				j++;
			}
			for (long int k = j; k <= n; k++){
				sum[j] -= 2;
			}
		}
	}
	
	//cout << result;
	
	return 0;
}
