#include <bits/stdc++.h>

using namespace std;
int n, vitriSoAm = -1, vitriSo0 = -1, vitriChon = -1; //tich am => am2duong = -1 => vitriSoAm > -1
long long int a[1005], soAmLonNhat = -1e12, am2duong = 1, p= 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] < 0&&a[i]>soAmLonNhat) soAmLonNhat = a[i], vitriSoAm = i;
		if (a[i] < 0) am2duong *= -1;
		if (a[i] == 0) vitriSo0 = i;
	}
	if (am2duong == -1) vitriChon = vitriSoAm; 
	else if (vitriSo0 > -1) vitriChon = vitriSo0;
	
	long long int product = 1;
	for (int i = 0; i < n; i++) if (i != vitriChon){
		product = (product*a[i])%p;
	}
	cout << product;
	
	return 0;
}
