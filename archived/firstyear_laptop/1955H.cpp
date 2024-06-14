#include<bits/stdc++.h>

using namespace std;
const int maxN = 55, maxR = 12;
int n, m, k, x[maxN*maxN], y[maxN*maxN], p[maxN*maxN], memo[maxN][maxN][maxR], f[maxN*maxN][1<<maxR];
int base3[20];
string s[maxN];
int sqr(int x){
	return x*x;
}
int calc(int x, int y, int r){
	if (memo[x][y][r-1]!=-1) return memo[x][y][r-1];
	int &res = memo[x][y][r-1];
	res = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) res += (s[i][j]=='#')&&(sqr(i-x)+sqr(j-y)<=sqr(r));
	}
	return res;
}
void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int l = 0; l < maxR; l++) memo[i][j][l] = -1;
	for (int i = 1; i <= n; i++){
		cin >> s[i];	
		s[i] = "#" + s[i];
	}
	int res = 0;
	base3[0] = 1;
	for (int i = 1; i <= 19; i++) base3[i] = base3[i-1]*3;
	for (int i = 1; i <= k; i++) cin >> x[i] >> y[i] >> p[i];
	for (int i = 1; i <= k; i++){
		for (int mask = 0; mask < (1<<maxR); mask++) f[i][mask] = 0;
		for (int mask = 0; mask < (1<<maxR); mask++){
			f[i][mask] = max(f[i][mask],f[i-1][mask]);
			for (int j = 0; j < maxR; j++) if (!(mask>>j&1)){
				int r = j+1;
				f[i][mask^(1<<j)] = max(f[i][mask^(1<<j)],f[i-1][mask]-base3[r]+p[i]*calc(x[i], y[i], r));
//				cout << x[i] << " " << y[i] << " " << bitset<4>(mask) << " " << r << " " << calc(x[i],y[i],r)*p[i]<< "\n";
				res = max(res,f[i][mask^(1<<j)]);
			}
			
		}
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

