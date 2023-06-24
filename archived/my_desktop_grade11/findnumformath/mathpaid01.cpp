#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;


bool check(unsigned long long int a, unsigned long long int b, unsigned long long int c, unsigned long long int d){
	return (((a*a*d*d+b*b*c*c)*(10*b+d) == (100*a+c)*(b*b*d*d)) && (__gcd(a,b)==1) && (__gcd(c,d)==1) && (__gcd(100*a+c,10*b+d)==1));
};

int main() {
	ifstream fi("input.inp");
	ofstream fo("output.out");
	
	//int a,b,c,d;
	int n;
	cin >> n;
	
	for (unsigned long long int a = 1; a <= n; a++){
		for (unsigned long long int b = 1; b <= n/10; b++){
			for (unsigned long long int c = 1; c <= n; c++){
				for (unsigned long long int d = 1; d <= n/10; d++){
					//if((a/b)*(a/b)+(c/d)*(c/d) == (100*a+c)/(100*b+d)){
					if (check(a,b,c,d)){
						cout << a << " " << b << " " << c << " " << d << " " <<(a*a*d*d+b*b*c*c)*(100*b+d) <<  " " << (100*a+c)*(b*b*d*d)<< endl;
					}
				}
			}
		}
	}
	
	fi.close();
	fo.close();
	return 0;
}
