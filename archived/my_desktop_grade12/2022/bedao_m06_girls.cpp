#include<bits/stdc++.h>

using namespace std;
long long n, a[1000005], m, k;
long long pref[1000005];
int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	pref[0] = a[0];
	for (int i = 1; i < n; i++) pref[i] = a[i] + pref[i-1];
	long long int res = -2;
	for (int i = 0; i < n-m+1; i++){
		if (a[i+m-1]-a[i]<=k) res = pref[i+m-1]-(i==0?0:pref[i-1]);
	}
	cout << res;
	
	
	return 0;
}
