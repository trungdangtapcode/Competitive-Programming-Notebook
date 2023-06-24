#include <iostream>
//#include <bits/stdc++.h>

using namespace std;
const int maxN = 5e6;
int h[maxN+5], n, x, y;
long long int res = 0;

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);	
//	memset(h,0,sizeof(h));
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		x /= 2; y /= 2;
		h[x] = max(h[x],y);
	}
	for (int i = maxN, mmax = 0; i >= 1; i--){
		mmax = max(mmax,h[i]);
		res += mmax;
	}
	cout << res*4;
	
	return 0;
}
