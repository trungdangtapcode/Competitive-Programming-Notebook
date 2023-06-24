#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long int res = 0;
	cin >> n;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		if (i&1) res += x;
	}
	cout << res;
	return 0;
}
