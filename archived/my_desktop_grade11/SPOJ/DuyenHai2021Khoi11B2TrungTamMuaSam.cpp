#include <bits/stdc++.h>

using namespace std;
const int p = 1e9+7;
vector<int> c[10005];
int n, k, f[10005];
bool disable[10005]; //thuc ra chi xai [0,9] (1->10)
int par[10005];
int dp[10005];

int dfs(int u){
	if (dp[u]!=-1) return dp[u];
	int res = 1;
	for (int v: c[u]) if (v!=par[u]&&!disable[f[v]]){
		par[v] = u;
		res = (1ll*res*(dfs(v)+1))%p;
	}
	return dp[u] = res;
}
int count(int mask){
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i < k; i++) disable[i] = (mask&(1<<i));
//	cout << disable[0] << " " << (mask&(1<<0)) << endl;
	int res = 0; 
	for (int i = 0; i < n; i++) if (!disable[f[i]]){
		res = (res+dfs(i))%p;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> f[i], f[i]--;
	for (int i = 0, x, y; i < n-1; i++) cin >> x >> y, c[x-1].push_back(y-1), c[y-1].push_back(x-1);
	
	//init par[]
	memset(dp,-1,sizeof(dp));
	par[0] = -1;
	dfs(0);
//	cout << count(1);

	int res = 0;
	for (int mask = 0; mask < (1<<k); mask++){
		int sign;
		if (__builtin_popcount(mask)%2==0) sign = 1; else sign = -1;
		res = (res+sign*count(mask))%p;
	}
	cout << (res+p)%p;
	
	return 0;
}
