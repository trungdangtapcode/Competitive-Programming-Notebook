#include <bits/stdc++.h>

using namespace std;

int n, dp[200005][2];
vector<int> edge[200005];
const int mod = 1e9+7;

void dfs(int u, int p){
	for (int v: edge[u]) if (v!=p){
		dfs(v,u);
		dp[u][0] = 1ll*dp[u][0]*(dp[v][0] + dp[v][1])%mod;
		dp[u][1] = 1ll*dp[u][1]*dp[v][0]%mod;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0, x, y; i < n-1; i++){
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for (int i = 1; i <= n; i++){
		dp[i][0] = dp[i][1] = 1;
	}
	dfs(1,-1);
	cout << (dp[1][0]+dp[1][1])%mod;
		
	return 0;
}


