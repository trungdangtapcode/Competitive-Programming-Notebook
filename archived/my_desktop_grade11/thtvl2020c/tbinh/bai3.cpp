#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
//#include <vector>

using namespace std;

struct num{
	long long int value;
	int trace;
};

bool func(num a, num b) {
	return (a.value < b.value);
}

int main() {
	ifstream fi("input.inp");
	ofstream fo("output.out");
	
	int n,m;
	num a[100];
	memset(a,0,sizeof(a));
	cin >> n >> m;
	for (int i = 0; i< n; i++){
		cin >> a[i].value;
		a[i].trace = i+1;
	}
	/*sort(a,a+n,func);
	long long int sum = 0;
	//for (int i = 0; i< n; i++) cout << a[i].value << endl;
	
	vector<int> v;
	for (int i = 0; i < m; i++){
		//cout << a[n-i-1].value << endl;
		sum += a[n-1-i].value;
		v.push_back(a[n-1-i].trace);
	}
	sort(v.begin(),v.end());
	cout << sum << endl;
	bool ch = false;
	for (vector<int>::iterator vi = v.begin(); vi!= v.end(); ++vi){
		if (ch) cout << " ";
		ch = true;
		cout << *vi;
	}
	*/
	
	fi.close();
	fo.close();
	return 0;
}
