#include<bits/stdc++.h>

using namespace std;
const int maxN = 20, maxB = (1<<maxN)+5, maxL = 105;
int n, eval[maxN][maxN], g[maxL][maxL];
string s[maxN];
int calc(int i, int j, int pi, int pj){
	if (g[pi][pj]!=1e9) return g[pi][pj];
	int &res = g[pi][pj];
	if (pi==s[i].length()&&pj==s[j].length()){
		return res=0;
	}
	if (pi<s[i].length()&&pj<s[j].length()){
		res = min(res,calc(i,j,pi+1,pj+1)
			+(s[i][pi]==s[j][pj]?1:2));
	}
	if (pi<s[i].length()){
		res = min(res,calc(i,j,pi+1,pj)+1);
	}
	if (pj<s[j].length()){
		res = min(res,calc(i,j,pi,pj+1)+1);
	}
	return res;
}
int f[maxB];
int dp(int cur, int mask){
	if (f[mask]!=1e9) return f[mask];
	int &res = f[mask];
	if (mask>>cur&1) return res = dp(cur+1,mask);
	mask ^= (1<<cur);
	for (int i = cur+1; i < n; i++) if ((mask>>i&1)==0){
		res = min(res,max(dp(cur+1,mask^(1<<i)),eval[cur][i]));
	}
	return res;
}

void solve(){
	cin >> n;
	n *= 2;
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
		for (int l1 = 0; l1 <= s[i].length(); l1++) for (int l2 = 0; l2 <= s[j].length(); l2++){
			g[l1][l2] = 1e9;
		}
		eval[i][j] = calc(i,j,0,0);
	}
	for (int i = 0; i < (1<<n); i++) f[i] = 1e9;
	f[(1<<n)-1] = 0;
	cout << dp(0, 0) << "\n";
//	for (int mask = 0; mask < (1<<n); mask++){
//		cout << bitset<4>(mask) << " " << f[mask]<< "\n";
//	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}
//https://pastebin.pl/view/a7893b95

