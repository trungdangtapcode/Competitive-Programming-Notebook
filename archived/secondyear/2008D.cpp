#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, p[maxN], f[maxN], g[maxN];
string s;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	cin >> s;
	for (int i = 1; i <= n; i++) f[i] = -1, g[i] = 0;
	int cnt = 0;
	function<void(int,int)> dfs = [&](int x, int y){
		if (f[x]!=-1) return;
		f[x] = y;
		g[y] += '1'-s[x-1];
		dfs(p[x],y);
	};
	for (int i = 1; i <= n; i++){
		if (f[i]==-1) dfs(i,++cnt);
		cout << g[f[i]] << " ";
	}
	cout << "\n";
//	exit(0);
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

