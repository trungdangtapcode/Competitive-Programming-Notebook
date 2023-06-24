#include <bits/stdc++.h>

using namespace std;
int n, m;
int a, b, a0, myGCD = 0;

int main(){
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		cin >> a;
		if (i==0) a0 = a;
		myGCD = __gcd(myGCD,a-a0);
	}
	for (int i = 0; i < m; i++){
		cin >> b;
		cout << abs(__gcd(a0+b,myGCD)) << " ";
	}
	
	return 0;
}
