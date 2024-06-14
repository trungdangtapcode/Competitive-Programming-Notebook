#include<bits/stdc++.h>

using namespace std;
string s;
int n, k, f[200005][15][26], g[200005][15];
int main(){
	cin >> n >> k >> s;
	s = "#" + s;
	g[0][0] = 1;
//	for (int c = 'a'; c <= 'z'; c++) f[0][0][c-'a'] = 1;
	for (int i = 0; i <= k; i++) g[i][i ] = 1;
	for (int i = 1; i <= n; i++){
		f[i][0][s[i]-'a'] = 1;
		g[i][0] = 1;
		for (int j = 1; j <= k; j++){
			for (int c = 'a'; c <= 'z'; c++){
				if (c==s[i]){
					f[i][j][c-'a'] += g[i-1][j];
				} else {
					f[i][j][c-'a'] += f[i-1][j-1][c-'a'];
				}
				g[i][j] += f[i][j][c-'a'];
				if (c<'c') cout << i << " " << j << " " << (char)c << " " << f[i][j][c-'a'] << "\n";
			}
			
		}
	}
//	cout << g[n][k];
	
	return 0;
}
