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

long long int f(long int x){
	return (x*(x-1)/2);
}

int main() {
	//ifstream fi("input.inp");
	//ofstream fo("output.out");
	
	
	long int n;
	int* a = new int[1000000];
	bool* ch = new bool[1000000];
	memset(ch,1,sizeof(ch));
	memset(a,1,sizeof(a));
	cin >> n;
	for (long int i= 0; i <n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i = 0; i< n; i++) cout << a[i]<<" "; cout << endl;
	long long int result = 0;
	long int index = 0;
	while (index<n){
		if (ch[index]){
			/*long int last_index = index;
			while (a[index] == a[last_index]){ //! Do dong lap khong the vuot qua 18 do 18! rat lon nen van tinh la O(n). Khong can dung Binary Search
				last_index++;
			} 
			for (long int i = index; i < last_index; i++){ //index not number, co nghia la last_index di qua 1 so
				ch[i] = false;
			}
			result += fac[(last_index-1)-index+1];
			index = last_index; //bat dau bang 1 so moi*/
			long int last_index = upper_bound(a,a+n,a[index])-a;
			for (long int i = index; i < last_index; i++)
				ch[i] = false;
			result += f((last_index-1)-index+1);
			cout << index << " " << last_index << " ->  "<< f((last_index-1)-index+1)<< endl;
			index = last_index;
		} else {
			index++;
			cout << index << endl;
		}
	}
	cout << result;
	
	
	//fi.close();
	//fo.close();
	return 0;
}
