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

long int findMedian(long int a[], long int n)
{
    sort(a, a + n);
    if (n % 2 != 0)
        return a[n / 2];
}
long int theMid(long int p[][], long int x, long int y, long int h, long int w){ //ko can dk
	long int arr[1000000];
	long int arr_size = 0;
	for (long int i = x; i < x+h; i++){
		for (long int j = y; j < y+w; j++){
			arr[arr_size] = p[i][j];
			arr_size++;
		}
	}
	return findMedian(arr,arr_size);
}

int main() {
	long int r,c,h,w;
	long int p[3001][3001];
	cin >> r >> c >> h >> w;
	for (long int i = 0; i < r; i++){
		for (long int j = 0; j < c; j++){
			cin >> p[i][j];
		}
	}
	cout << theMid(p,0,0,h,w);
	return 0;
}
