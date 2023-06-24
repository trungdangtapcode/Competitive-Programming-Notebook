#include<bits/stdc++.h>

using namespace std;
long long a[305], f[305][305][155];
int n, k;
int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int l = 1; l <= k; l++) f[i][j][l] = -1e12;
	for (int i = 1; i <= n; i++) for (int j = i-1; j > 0; j--) for (int l = 1; l <= k; l++){
		f[j][i][l] = max({
			f[j+2][i][l-1] + abs(a[j]-a[j+1]),
			f[j][i-2][l-1] + abs(a[i]-a[i-1]),
			f[j+1][i-1][l-1] + abs(a[i]-a[j]),
			f[j+1][i][l],
			f[j][i-1][l]
		});
	}
	cout << f[1][n][k];
	
	return 0;
}
