#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const ii d[] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int n, m, a[1005][1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int res = 0;
			for (int k = 0; k < 8; k++){
				int ii = i + d[k].first, jj = j + d[k].second;
				res += a[ii][jj];
			}
			cout << res << " ";
		}	
		cout << "\n";
	}
	
	
	return 0;
}
