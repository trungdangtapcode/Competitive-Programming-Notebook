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
string s, s0;
long int n, k;
long int **tanso = new long int*[27];
long int *myMax = new long int[100001];


bool check(long int pivot, long int m){
	long int result = 0;
	for (int i = 0; i < 27;i++){
		result = max(result,tanso[i][m]-tanso[i][pivot-1]);
	}
	return (result<=k);
}
long int BIT(long int pivot){ // [1, 1, 1, 1, 0, 0, 0]
	long int l = pivot, h = n;
	long int m = (l+h)/2;
	while (l<h){
		//cout << m << endl;
		if (check(pivot,m)) l = m; else h = m;
		m = (l+h)/2;
		if (l == h -1) if (check(pivot,h)) return h; else return l;
	}
	return m;
}

int main() {
	for (int i = 0 ; i < 27 ; i++) tanso[i] = new long int[100001]; 
	cin >> n >> k >> s0;
	s = ' ' + s0;
	for (int i = 0; i <= n; i++) for (int j = 0; j < 27; j++) tanso[j][i] = 0;
	for (int i = 1; i <= n; i++){
		tanso[int(s[i])-int('a')][i] = tanso[int(s[i])-int('a')][i-1] + 1;
		for (int j = 0; j < 27; j++) if (j!=int(s[i])-int('a')) tanso[j][i] = tanso[j][i-1];
		myMax[i] = 0;
		for (int j = 0; j < 27; j++) myMax[i] = max(myMax[i],tanso[j][i]);
	}
	
	/*for (int i = 1; i <= n; i++){
		for (int j = 0; j < 27; j++){
			cout << tanso[j][i] << " ";
		}
		cout << "     max = "<< myMax[i] << endl;
	}*/
	long int result = 0, result_index = 0;
	for (int i = 1; i <= n; i++){
		long int x = BIT(i)-i+1;
		if (result < x){
			result = x;
			result_index = i;
		}
	}
	cout << result << " " << result_index;
	
	
	
	return 0;
}
