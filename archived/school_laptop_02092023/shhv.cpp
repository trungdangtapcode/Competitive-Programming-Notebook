#include<bits/stdc++.h>

using namespace std;
int n, check[20];
long long a[20], fact[20], p, x;
int main(){
	fact[0] = 1;
	for (int i = 1; i <= 12; i++) fact[i] = fact[i-1]*i;
	while (cin >> x){
		if (x==0) break;
		a[++n] = x;
 	}
 	p = a[n--];
 	long long res1 = 1;
	for (int i = 1; i <= n; i++){
		int cur = a[i];
		for (int j = 1; j <= i; j++) cur -= (a[j]<=a[i]);
		res1 += cur*fact[n-i];
	}
	cout << res1 << "\n";
	long long lessthan = p-1;
	for (int i = 1; i <= n; i++) check[i] = 1;
	for (int i = 1; i <= n; i++){
		int cur = lessthan/fact[n-i];
		lessthan -= cur*fact[n-i];
		int x = -1;
		for (int j = 1; cur >= 0; j++) if (check[j]) cur--, x = j;
		check[x] = 0;
		cout << x << " ";
	}
	
	return 0;
}
