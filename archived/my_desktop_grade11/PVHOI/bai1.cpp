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
long int *p = new long int[3001*3001];
long int findMedian(long int a[], long int n)
{
    sort(a, a + n);
    if (n % 2 != 0)
        return a[n / 2];
}
long int theMid(long int x, long int y,long int r, long int c, long int h, long int w){ //ko can dk
	long int *arr = new long int[1000000];
	long int arr_size = 0;
	for (long int i = x; i < x+h; i++){
		for (long int j = y; j < y+w; j++){
			arr[arr_size] = p[i*c+j];
			arr_size++;
		}
	}
	return findMedian(arr,arr_size);
}

int main() {
	long int r,c,h,w;
	cin >> r >> c >> h >> w;
	for (long int i = 0; i < r; i++){
		for (long int j = 0; j < c; j++){
			cin >> p[i*c+j];
		}
	}
	long int result = -1e5;
	for (long int i = 0; i <= r-h; i++){
		for (long int j = 0; j <= c-w; j++){
			result = max(result,theMid(i,j,r,c,h,w));		
		}
	}
	cout << result;
	/*for (long int i = 0; i < r; i++){
		for (long int j = 0; j < c; j++){
			cout << p[i*c+j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}
