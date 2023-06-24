/*
a*abs(x-p[i]) + a*abs(y-p[j]) + b*(p[j]-p[i])
p[j]< y => delta = a*y - a*p[j] + b*p[j]
p[j]> y => delta = -a*y + a*p[j] + b*p[j]
*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e6+5;
//int f[maxN], g[maxN], pref[maxN];
int n, m, q, a, b, p[maxN], prv[maxN], nxt[maxN];
bool check[maxN];

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q >> a >> b;
	for (int i = 1; i <= m; i++){
		cin >> p[i];
		check[p[i]] = 1;
	};
	prv[0] = -1e9; nxt[n+1] = 1e9;
	for (int i = 1; i <= n; i++){
		prv[i] = (check[i]?i:prv[i-1]);
	}
	for (int i = n; i > 0; i--){
		nxt[i] = (check[i]?i:nxt[i+1]);
	}
	
	while (q--){
		int x, y;
		cin >> x >> y;
		if (x>y) swap(x,y);
		int res = (y-x)*a;
		res = min(res,a*abs(x-prv[x]) + a*abs(y-prv[y]) + b*(prv[y]-prv[x]));
		res = min(res,a*abs(x-prv[x]) + a*abs(y-nxt[y]) + b*(nxt[y]-prv[x]));
		res = min(res,a*abs(x-nxt[x]) + a*abs(y-prv[y]) + b*(prv[y]-nxt[x]));
		res = min(res,a*abs(x-nxt[x]) + a*abs(y-nxt[y]) + b*(nxt[y]-nxt[x]));
		cout << res << "\n"; 
	}
	
	return 0;
}
