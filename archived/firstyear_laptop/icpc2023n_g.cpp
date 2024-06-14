#include<bits/stdc++.h>

using namespace std;
string s;
int n, k, f[200005][15][26], g[200005][15];
int main(){
	cin >> n >> k >> s;
//	n = s.length();
	s = "#" + s;
	for (int i = 1; i <= n; i++){
//		for (int c = 'a'; c <= 'z'; c++){
//			if (c==s[i]){
//				f[i][1][c-'a'] = g[i-1][1] - f[i-1][1][c-'a'] + 1;
//			} else {
//				f[i][1][c-'a'] = f[i-1][1][c-'a'];
//			}
//			g[i][1] += f[i][1][c-'a'];
//		}
//		f[i][1][s[i]-'a'] = 1;
//		g[i][1] += 1;
		for (int j = 0; j <= k; j++){
			for (int c = 'a'; c <= 'z'; c++){
				if (c==s[i]){
///					f[i][j][c-'a'] = g[i-1][j-1] - f[i-1][j-1][c-'a']*0 + f[i-1][j][c-'a'];
//					f[i][j][c-'a'] = g[i-1][j-1] + g[i-1][j] - f[i-1][j][c-'a'];
					f[i][j][c-'a'] = g[i-1][j+1];
				} else {
					f[i][j][c-'a'] = f[i-1][j][c-'a'];
				}
				g[i][j] += f[i][j][c-'a'];
			}
		}
	}
//	cout << g[n][k];
	
	return 0;
}
