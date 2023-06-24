#include<bits/stdc++.h>

using namespace std;

int calc(long long x){
	int res = 0;
	while (x){
		res += x%10;
		x /= 10;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	long long res = 0;
	for (long long i = 0, u = 0, d = 3; i < n; i++, u += d, d += 2){
		res += calc(u);
	}
	cout << res;
	
	return 0;
}
