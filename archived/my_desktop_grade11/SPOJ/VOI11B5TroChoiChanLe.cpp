#include <bits/stdc++.h>

using namespace std;
int n;
long long int a[505][505], sx[505][505], sy[505][505];
bool f[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while (t--){
		memset(sx,0,sizeof(sx));
		memset(sy,0,sizeof(sy));
		cin >> n;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) 
			cin >> a[i][j], sx[i][j] = sx[i-1][j] + a[i][j], sy[i][j] = sy[i][j-1] + a[i][j];
		
		memset(f,false,sizeof(f));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++){
				if (sy[i][j]%2==0) f[i][j] |= !f[i-1][j];
				if (sx[i][j]%2==0) f[i][j] |= !f[i][j-1];
				//cout << f[i][j] << " ";
			}
			//cout << endl;
		}
		cout << (f[n][n]?"YES":"NO") << '\n';
	}
	
	return 0;
}
