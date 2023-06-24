#include <bits/stdc++.h>

using namespace std;
int n, m;
vector <int> edge[100005];
int dp[100005];

int dfs(int nodeU){
	if (dp[nodeU]!=-1) return dp[nodeU];
	for (auto& nodeV: edge[nodeU]){
		dp[nodeU] = max(dp[nodeU],dfs(nodeV)+1);
	}
	dp[nodeU] = max(dp[nodeU],0); //cung duong
	return dp[nodeU];
}

int main(){
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) dp[i] = -1;
	
	int res = 0;
	for (int i = 1; i <= n; i++){
		res = max(res,dfs(i));
	}
	cout << res;
	
	return 0;
}
