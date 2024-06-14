#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n, m, a[maxN][maxN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		int cur = 0, res = 0;
		for (int i = 1; i <= n; i++){
			bool check = 1;
			for (int j = 2; j <= m; j++){
				if (a[i][j-1]!=a[i][j]) check = 0;
			}
			cur += (check);
		}
		for (int i = 1; i <= m; i++){
			bool check = 1;
			for (int j = 2; j <= n; j++){
				if (a[j-1][i]!=a[j][i]) check = 0;
			}
			res += (check)*cur;
		}
		cout << res << "\n";
	}
	return 0;
}
