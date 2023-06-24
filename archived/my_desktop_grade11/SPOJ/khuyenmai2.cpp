#include <bits/stdc++.h>
#define fix cout << "fixed "  << endl;

using namespace std;
int n, f[1001][1001];
vector<int> a;
int main(){
	cin >> n;
	a.push_back(0);
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i <= n; i++) for (int j = 0; j <=n; j++) f[i][j] = 4e6;
	f[0][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= n; j++){
			f[i][j] = f[i-1][j+1];;
			if (a[i]>100&&j>0) {
				f[i][j] = min(f[i][j],f[i-1][j-1]+a[i]);
			} else f[i][j] = min(f[i][j],f[i-1][j]+a[i]);
		}
	}
//	for (int i = 0; i <= n; i++){
//		for (int j = 0; j <= n; j++)
//			cout << f[i][j] << " ";
//		cout << endl;
//	}
	cout << f[n][0];
	return 0;
}
