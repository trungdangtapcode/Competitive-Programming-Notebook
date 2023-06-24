#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<vector<int>> a;
vector<vector<ii>> op;
int n, m, k;
const int p = 3;

int calc(int x){
	int res = 0;
	vector<vector<int>> f(n+5,vector<int>(m+5,0));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		//getS -> now val
		f[i][j] = ((f[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1])%p+p)%p;
		int cur = ((f[i][j]+a[i][j])%p+p)%p;
		if (cur == x) continue;
		//calc cnt step -> predict
		if (op[i][j]==ii{-1,-1}) return 1e9;
		int cnt = ((x-cur)%p+p)%p;
		res += cnt;
		f[i][j] += cnt;
		f[i][op[i][j].second+1] -= cnt;
		f[op[i][j].first+1][j] -= cnt;
		f[op[i][j].first+1][op[i][j].second+1] += cnt;
	}
	return res;
}

int main(){
	cin >> n >> m >> k;
	a.resize(n+5,vector<int>(m+5));
	op.resize(n+5,vector<ii>(m+5,{-1,-1}));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		cin >> a[i][j];
	}
	for (int i = 0, x, y, u, v; i < k; i++){
		cin >> x >> y >> u >> v;
		op[x][y] = {u,v};
	}
	int res = min(calc(1),calc(2));
	if (res==1e9) res = -1;
	cout << res;
	
	return 0;
}
