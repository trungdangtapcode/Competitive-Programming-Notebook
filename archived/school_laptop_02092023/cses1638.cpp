#include<bits/stdc++.h>

using namespace std;
int n, f[1005][1005];
char c;
const int p = 1e9+7;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
		cin >> c;
		if (c=='*') continue;
		if (i==1&&j==1) f[i][j] = 1;
		f[i][j] = (f[i][j]+f[i][j-1]+f[i-1][j])%p;	
	}
	cout << f[n][n];
	
	return 0;
}
