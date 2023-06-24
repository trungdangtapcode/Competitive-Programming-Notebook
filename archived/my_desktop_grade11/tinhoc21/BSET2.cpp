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
	
	long int n, m;
	long int a[100000];
	long int b[100000];
	long int c[200000];
	cin >> n >> m;
	for (long int i = 0; i < n; i++){
		cin >> a[i];
		c[i] = a[i];
	}
	for (long int i = 0; i < m; i++){
		cin >> b[i];
		c[i+n] = b[i];
	}
	set<long int> set_a(a,a+n);
	set<long int> set_b(b,b+m);
	set<long int> set_c(c,c+n+m);
	cout << set_c.size() <<" " <<set_a.size()+set_b.size()-set_c.size() << endl;
	//for (long int it: set_a){
	//	cout << it;
	//}
	
	return 0;
}
