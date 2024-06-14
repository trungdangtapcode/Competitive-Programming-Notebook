#include<bits/stdc++.h>

using namespace std;
const int maxN = 15;
typedef pair<int,int> ii;
int n, a[maxN], g[maxN][maxN];
bitset<maxN> f[maxN][maxN];
void solve1(){
	int res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		f[i][i][a[i]] = 1;
		
	}
	for (int i = n; i >= 1; i--){
		for (int j = i+1; j <= n; j++){
			for (int k = i; k < j; k++){
				f[i][j] |= f[i][k]&(f[k+1][j]>>1);
				f[i][j] |= (f[i][k]>>1)&f[k+1][j];
			}
			cout << i << ".." << j << " " << f[i][j] << "\n";
		}
	}
}
void solve(){
	int res = 0;
	cin >> n;
	memset(g,-1,sizeof(g));
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		g[i][i] = a[i];
	}
	for (int i = n; i >= 1; i--){
		for (int j = i+1; j <= n; j++){
			for (int k = i; k < j; k++) if (g[i][k]!=-1&&g[k+1][j]!=-1&&abs(g[i][k]-g[k+1][j])==1){
				g[i][j] = min(g[i][k],g[k+1][j]);
				cout << i << ".." << j << " " << g[i][j] << " " << k << "\n";
			}
//			cout << i << ".." << j << " " << f[i][j] << "\n";
		}
	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
	return 0;
}
