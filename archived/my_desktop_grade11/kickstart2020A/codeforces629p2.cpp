#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	--k;
	
	int p1, p2;
	for (int i = n-2; ~i; --i){
		cout << i << " " << k << " < " << n-1-i << endl;
		if (k<n-1-i){
			p1 = i;
			p2 = n-1-k;
			break;
		}
		k -= n-1-i;
	}
	
}
