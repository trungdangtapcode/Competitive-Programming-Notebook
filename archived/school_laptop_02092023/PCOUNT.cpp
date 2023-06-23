#include<bits/stdc++.h>

using namespace std;
#define int long long
int f[1005][1005], n, k;
const int p = 1e9+7;

main(){
	cin >> n >> k;
	f[0][0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			f[i+1][j] = (f[i+1][j]+f[i][j]*(j+1))%p;
			f[i+1][j+1] = (f[i+1][j+1]+f[i][j]*(i-j))%p;
		}
	}
	cout << f[n][k];
	
	return 0;
}
