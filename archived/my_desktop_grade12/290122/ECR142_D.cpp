#include<bits/stdc++.h>

using namespace std;
int n, m, p[100005][11], pt[100005][11], to[1000005][11], ntrie;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
//	int t = 1;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> p[i][j];
				pt[i][p[i][j]] = j;
			}
		}
		int root = ++ntrie;
		for (int i = 1; i <= n; i++){
			int u = root;
			for (int j = 1; j <= m; j++){
				int c = pt[i][j];
				if (to[u][c]==0) to[u][c] = ++ntrie;
				u = to[u][c];
			}
		}
		for (int i = 1; i<= n; i++){
			int u = root, res = 0;
			for (int j = 1; j <= m; j++){
				int c = p[i][j];
				if (to[u][c]==0) break;
				u = to[u][c];
				res++;
			}
			cout << res << " ";
		}
		cout << "\n";
				
//		cout << "\n";
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= m; j++) cout << pt[i][j] << " ";
//			cout << "\n";
//		}
	}
	
	return 0;
}
