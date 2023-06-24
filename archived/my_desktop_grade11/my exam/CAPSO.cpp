#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int binarySearch(int arr[], int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
      return mid ;
      if (arr[mid] > num)
      return binarySearch(arr, p, mid-1, num);
      if (arr[mid] < num)
      return binarySearch(arr, mid+1, r, num);
   }
   return -1;
}
int main() {
	ifstream fi("capso.inp");
	ofstream fo("output.out");
	
	int n, m, S,x, count = 0;
	int a[100001], b[100001];
	//int bucketA[200];
	//su dung nhi phan tim kiem vi chua biet duoc S :3
	
	fi >> n >> m >> S;
	//cout << n << endl;
	for (int i = 0; i < n; i++){
		fi >> a[i];
	}
	//for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
	for (int i = 0; i < m; i++){
		fi >> b[i];
	}
	
	//haha chua sort ma da BS roi :vvv
	sort (a, a + n);
	sort (b, b + m);
	for (int i = 0; i < m; i++){
		x = S - b[i];
		if (binarySearch(a,0,n,x) != -1) count++;
		x = -S - b[i];
		if (binarySearch(a,0,n,x) != -1) count++;
	}
	//cout << binarySearch(a,0,n,-6) << endl;
	cout << count << endl;
	
	fi.close();
	fo.close();
	return 0;
}
