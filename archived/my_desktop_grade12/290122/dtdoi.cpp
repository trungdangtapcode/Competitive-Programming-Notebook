#include<bits/stdc++.h>

using namespace std;
int n, a[105], f[20005], res, s, mmax;
int main(){
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mmax = max(mmax,a[i]);
	}
	for (int j = 1; j <= 2e4; j++) f[j] = 1e9;
	for (int i = 0; i < n; i++){
		for (int j = a[i]; j <= 2e4; j++) f[j] = min(f[j],f[j-a[i]]+1);
	}
	if (s<=2e4){
		cout << f[s] << "\n";
	} else {
		int res = (s-2e4)/mmax+1;
		s -= mmax*res;
		cout << res + f[s] << "\n";
	}
	
	return 0;
}
