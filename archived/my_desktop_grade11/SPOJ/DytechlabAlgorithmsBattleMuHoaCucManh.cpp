#include <bits/stdc++.h>

using namespace std;
int n, cur;
const int p = 1e9+7;
int power(int x, int y, int p){
	int res = 1;
	while (y>0){
		if (y%2) res = 1ll*res*x%p;
		x = 1ll*x*x%p;
		y /= 2;
	}
	return res;
}
int main(){
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int res = 0;
	for (int i = 0; i < n; i++){
		for (int j = i; j >= 0; j--) {
			cur = 1;
			for (int k = i; k >= j; k--)
				cur  = power(a[k],cur,p-j+k);// , cout << j <<" " << i << " " << cur << endl;
			res = (res+cur)%p;
		}
	}
	cout << res;
}
