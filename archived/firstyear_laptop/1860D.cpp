#include<bits/stdc++.h>

using namespace std;
const int maxN = 105, T = 5000;
int n, f[maxN][maxN*maxN], g[maxN][maxN*maxN];
string s;
void solve(){
	cin >> s;
	n = s.length();
	s = " " + s;
//	for (int i = -n*n/2; i <= n*n/2; i++) f[0][i+T] = 1e9;
	f[0][T] = 0;
	int scnt0 = 0;
	for (int i = 1, cnt[2] = {0}; i <= n; scnt0 += s[i]=='0',i++){
		for (int j = -i*i/2; j <= i*i/2; j++){
			for (int cnt0 = 0; cnt0 <= i; cnt0++){
				g[cnt0][j+T] = 1e9; 
			}
		}
		for (int j = -(i-1)*(i-1)/2; j <= (i-1)*(i-1)/2; j++){ //j = pair 01
			for (int cnt0 = 0, cnt1 = i-1; cnt0 < i; cnt0++, cnt1--){
				g[cnt0+1][j-cnt1+T] = min(g[cnt0+1][j-cnt1+T],f[cnt0][j+T] + (s[i]!='0'));
				g[cnt0][j+cnt0+T] = min(g[cnt0][j+cnt0+T],f[cnt0][j+T] + (s[i]!='1'));
			}
		}
		for (int j = -i*i/2; j <= i*i/2; j++){
			for (int cnt0 = 0; cnt0 <= i; cnt0++){
//				if (g[cnt0][j+T]<1) cout << i << ". cnt0=" << cnt0 << " j=" << j << " \t" << g[cnt0][j+T] << "\n"; 
				f[cnt0][j+T] = g[cnt0][j+T]; 
			}
		}
	}
//	cout << f[3][0+T];
//	int res = 1e9;
//	for (int i = 0; i <= n; i++) res = min(res,f[i][T]);
	cout << f[scnt0][T]/2 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

