#include<bits/stdc++.h>

using namespace std;
int n, k, d[10];
long long res =0;
long long nCr(int n, int k){
	long long res = 1;
	for (int i = n; i > n-k; i--) res *= i;
	for (int i = 1; i <= k; i++) res /= i;
	return res;
}

int main(){
	cin >> n >> k;
	
	d[0] = 1;
	d[1] = 0;
	for (int i = 2; i <= k; i++) d[i] = (i-1)*(d[i-1]+d[i-2]);
	for (int i = 0; i <= k; i++){
		res += nCr(n,i)*d[i];
	}
	cout <<res;
	
	return 0;
}
