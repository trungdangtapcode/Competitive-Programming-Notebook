#include<bits/stdc++.h>

using namespace std;
int n, a[505][505], f[505][505][2];
const int p = 1e9+7;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
	for (int i = 1; i <= n; i++) f[i][i][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = i-1; j > 0; j--){
			for (int k = j; k <= i; k++){
				(f[j][i][0] += 1ll*f[j][k][1]*(f[k][i][0]+f[k][i][1])%p)%=p; //exlusion
			}
			if (a[j][i]) for (int k = j; k < i; k++) 
				(f[j][i][1] += 1ll*(f[j][k][0]+f[j][k][1])*(f[k+1][i][0]+f[k+1][i][1])%p)%=p;
		}
	}
	cout << (f[1][n][0]+f[1][n][1])%p;
	
	
	return 0;
}
