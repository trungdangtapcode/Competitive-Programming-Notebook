#include <bits/stdc++.h>
//a + 2*b + 3*c = n
//a + 2*b = n - 3*c
//a + 2*b = x
//a = x - 2*b
//a is any positive numbers
//0 <= x - 2*b <= x
//there are x/2+1 pairs of (a,b)

using namespace std;
int n, x, res;
const int p = 1e9+7;

int main(){
	cin >> n;
	for (int c = 0; c <= n/3; c++){
		x = n - 3*c;
		res = (res+x/2+1)%p;
	}
	cout << res;
	return 0;
}
