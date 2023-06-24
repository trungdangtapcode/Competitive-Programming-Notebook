#include <bits/stdc++.h>

using namespace std;

int addGcd(int a, int m){
	auto eulerTotient = [](int n){
		int res = n;
		for (int i = 2; i*i <= n; i++) {
			if (n%i==0) res -= res/i; //res *= (1-1/i)
			while (n%i==0) n /= i;
		}
		if (n>1) res -= res/n;
		return res;
	};
	int d = __gcd(a,m);
	return eulerTotient(m/d);
}

int main(){
	int a, m;
	cin >> a >> m;
	cout << addGcd(a,m);
	return 0;
}
