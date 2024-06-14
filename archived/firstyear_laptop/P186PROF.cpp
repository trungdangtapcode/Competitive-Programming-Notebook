#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1<<15, maxLenA = 1e5+5;
int n, k, a[maxLenA], f[16][maxN+5][16];
main(){
	cin >> n >> k;
	long long res0 = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		res0 += f[0][a[i]][0];
		f[0][a[i]][0]++;
	}
	if (k==0){
		cout << res0 << "\n";
		return 0;
	}
	for (int i = 0; i < 15; i++){
		for (int mask = 0; mask < maxN; mask++){
			for (int j = 0; j <= i+1; j++){
				f[i+1][mask][j] = f[i][mask][j];
				if (j>0) f[i+1][mask][j] += f[i][mask^(1<<i)][j-1];
			}
		}
	}
	long long res = 0;
	for (int i = 1; i <= n;i++) res += f[15][a[i]][k];
	cout << res/2 << "\n";

	
	return 0;
}
