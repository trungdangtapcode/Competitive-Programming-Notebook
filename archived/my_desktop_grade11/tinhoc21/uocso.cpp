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
	
void solve(){
	long long int n, m;
	cin >> n >> m; //a, b do
	long long int theMax = max(n,m);
	
	long long int i = 2;
	long long int result = 1;
	while ((n != 1 || m != 1) && i*i<=theMax){ //better than i*i <= n only, you see
		long long int count = 0;
		while (n%i == 0){
			n /= i;
			count++;
		}
		while (m%i == 0){
			m /= i;
			count++;
		}
		result *= (count+1); 
		i++;
	}
	//if (n!=1) result *= 2;
	//if (m!=1&&m!=n) result *= 2; //con m!=n nua huhu
	if (n!=1&&m!=1&&n!=m) result *= 4; //khong dung /2*3 vi so ra so le co sai so
	else if (n!=1&&m!=1&&n==m) result *= 3;
	else if (n!=1||m!=1) result *= 2;
	cout << result << endl;
}
	
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		solve();
	}
	return 0;
}
