#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[405], b[405], f[405][405], s[405], res = -1e9;

main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i];
		b[i] += b[i-1];
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			f[i][j] = (i>j?b[i]-b[j-1]:a[j]-a[i-1]);
		}
	}
	for (int i = 1; i <= n; i++){
		for (int k = 1; k <= n; k++) s[k] = 0;
		for (int j = i; j <= n; j++){
			for (int k = 1; k <= n; k++) s[k] += f[j][k];
			int cur = 0;
			for (int k = 1; k <= n; k++){
				cur = max(cur,0ll);
				cur += s[k];
				res = max(res,cur);
			}
		}
	}
	cout << res;
	
	return 0;
}
