#include<bits/stdc++.h>

using namespace std;
#define int long long
int calc(int x, int n){
	int y1 = (n/x+1)/2;
	int y2 = (x+1)/2;
	return min(abs(x-y1),abs(n/x-y2));
}

main(){
	int n, res = 1e18;	
	cin >> n;
	for (int i = 1; i*i <= 2*n; i++) if (2*n%i==0) res = min(res,calc(i,2*n));
	for (int i = 1; i*i <= 2*n+1; i++) if ((2*n+1)%i==0) res = min(res,calc(i,2*n+1));
	for (int i = 1; i*i <= 2*n-1; i++) if ((2*n-1)%i==0) res = min(res,calc(i,2*n-1));
	cout << res;
	
	return 0;
}
