#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, k, x[1000005], y[1000005], c, d, e1, e2, f, a[1000005], sumPow[1000005];
const int p = 1e9+7;
int getPow(int x, int y){
	int res = 1;
	while (y){
		if (y&1) res = (res*x)%p;
		x = (x*x)%p;
		y /= 2;
	}
	return res;
}
void read(){
	cin >> n >> k >> x[1] >> y[1] >> c >> d >> e1 >> e2 >> f;
	for (int i = 2; i <= n; i++) x[i] = (c*x[i-1]+d*y[i-1]+e1)%f, y[i] = (d*x[i-1]+c*y[i-1]+e2)%f;
	for (int i = 1; i <= n; i++) a[i] = (x[i]+y[i])%f;
	sumPow[1] = k;
	for (int i = 2; i <= n; i++) sumPow[i] = (sumPow[i-1]+(getPow(i,k+1)-1)*getPow(i-1,p-2)%p-1)%p;
}

main(){
	int t; cin >> t;
	while (t--){
		read();
		int res = 0;
		for (int i = 1; i <= n; i++){
			res += a[i]%p*sumPow[i]%p*(n-i+1)%p;
			res %= p;
		}
		cout << res << "\n";
	}
	
	return 0;
}
