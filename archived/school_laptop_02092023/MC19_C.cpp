#include<bits/stdc++.h>

using namespace std;
int n, cur, res[1005][1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n/2; i++){
		for (int j = 1; j <= n/2; j++){
			res[i][j] = cur*4;
			res[i+n/2][j] = cur*4+1;
			res[i][j+n/2] = cur*4+2;
			res[i+n/2][j+n/2] = cur*4+3;
			cur++;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) cout << res[i][j] << " ";
		cout << "\n";
	}
	
	return 0;
}
