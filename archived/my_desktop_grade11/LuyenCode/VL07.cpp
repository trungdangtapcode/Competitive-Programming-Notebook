#include <bits/stdc++.h>

using namespace std;
int n, k;
long long int tu = 1, mau = 1;
int main(){
	
	cin >> n >> k;
	if (k>n/2) k = n - k;
	for (int i = 1; i <= k; i++) mau *= i;
	for (int i = n-k+1; i <= n; i++) tu *= i;
	cout << tu/mau;
	
	return 0;
}
