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

struct myNum{
	long int soLuong;
	long int value;
	long int trace;
	long int soMua;
};

bool myFunc1(myNum x, myNum y){
	return (x.value<y.value);
}
bool myFunc2(myNum x, myNum y){
	return (x.trace<y.trace);
}

int main() {
	long int n, m;
	myNum a[20000];
	cin >> m >> n;
	for (long int i = 0; i < n; i++){
		cin >> a[i].soLuong >> a[i].value;
		a[i].trace = i;
	}
	sort(a,a+n,myFunc1);
	long int i = 0;
	long long int money = 0;
	while (m>0){
		if (m>a[i].soLuong) {
			a[i].soMua = a[i].soLuong;
			m -= a[i].soLuong;
		} else {
			a[i].soMua = m;
			m = 0;
		}
		money += a[i].soMua*a[i].value;
		//cout << a[i].soLuong << " " << a[i].value << "   daBan = "<< a[i].soMua <<"    m = " << m << endl;
		i++;
	}
	cout << money << endl;
	sort(a,a+n,myFunc2);
	for (long int i = 0; i < n; i++){
		cout << a[i].soMua << endl;
	}
	
	return 0;
}
