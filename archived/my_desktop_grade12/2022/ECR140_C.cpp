#include<bits/stdc++.h>

using namespace std;
int a[105][105], f[105][105], n;
const int p = 998244353;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) cin >> a[i][j];
	if (a[1][1]!=2) f[1][1] = 2;
	for (int i = 2; i <= n; i++){
		for (int j = 1; j < i; j++) f[i][j] = f[i-1][j];
		for (int j = 1; j < i; j++) (f[i][i] += f[i-1][j]) %= p;
		int l = i+1, r = 0;
		for (int j = 1; j <= i; j++){
			if (a[j][i]==1) l = min(l,j);
			if (a[j][i]==2) r = max(r,j);
		}
		for (int j = 1; j <= i; j++) if (j>l||j<=r) f[i][j] = 0;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) (res += f[n][i]) %= p; 
	cout << res;
	
	return 0;
}
