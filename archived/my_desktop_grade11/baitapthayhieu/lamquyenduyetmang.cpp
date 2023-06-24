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
	ifstream fi("input.inp");
	ofstream fo("output.out");
	
	//khoi tao
	int n;
	cin >> n;
	int a[100000];
	memset(a,1,sizeof(a));
	for (int i = 0; i < n; i++) cin >> a[i];
		
	//bai a
	int sorted_a[100000];
	memcpy(&sorted_a, &a, sizeof(a));
	sort(sorted_a,sorted_a+sizeof(sorted_a)/sizeof(sorted_a[0]));
	for (int i = 0; i < n; i++) cout << sorted_a[i] << " ";
	cout << endl;
	
	//bai b
	int dp[100000];
	dp[n] = 0;
	for (int i = n-1; i >= 0; i--){
		if (a[i]<a[i+1]) dp[i] = dp[i+1] + 1;
			else dp[i] = 1;
	}
	int b_max = 0;
	int b_max_index = 0;
	for (int i = 0; i < n; i++){
		if (b_max < dp[i]){
			b_max = dp[i];
			b_max_index = i;
		}
	}
	for (int i = 0; i < b_max; i++) cout << a[b_max_index+i] << " ";
	cout << endl;
	
	//bai c
	int trace[100000];
	int dp2[100000];
	dp[n] = 0;
	for (int i = n-1; i >= 0; i--){
		int max_dp2 = 0;
		int max_dp2_index = 0;
		for (int j = i+1; j < n; j++)
			if ((max_dp2 < dp2[j])&&(a[i] < a[j])) {
				max_dp2 = dp2[j];
				max_dp2_index = j;
			}
		dp2[i] = max_dp2+1;
		trace[i] = max_dp2_index;
	}
		//for (int i = 0; i < n; i++) cout <<trace[i] << " ";
	int c_max = 0;
	int c_max_index = 0;
	for (int i = 0; i < n; i++){
		if (c_max < dp2[i]){
			c_max = dp2[i];
			c_max_index = i;
		}
	}
	int pointer = c_max_index;
	for (int i = 0; i < c_max; i++) {
		cout << a[pointer] << " ";
		pointer = trace[pointer];
	}
	cout << endl;
	
	fi.close();
	fo.close();
	return 0;
}
