#include <bits/stdc++.h>

using namespace std;
int n;
long long int a[1005];
long double mmax = -1e9-5, mmin = 1e9+5;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			mmax = max(mmax,1.0l*(a[j]-a[i-1])/(j-i+1));
			mmin = min(mmin,1.0l*(a[j]-a[i-1])/(j-i+1));
		}
	}
	cout << fixed << setprecision(3) << mmin << " " << mmax;
	
	return 0;
}
