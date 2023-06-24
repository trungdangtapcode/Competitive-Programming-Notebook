#include <bits/stdc++.h>

using namespace std;
int n, k, a, b;
long long int dp[1005][1005][5];
vector<int> edge[1005];
int nEdge[1005];

void dfs(int nodeU, int nodeP){
	dp[nodeU][0][0] = dp[nodeU][0][1] = 1;
	for (int nodeV: edge[nodeU]){
		if (nodeV==nodeP) continue;
		dfs(nodeV,nodeU);
		//loop down ko can cai dat tmp dp
		for (int curEdge = nEdge[nodeU]; curEdge >= 0; curEdge--) for (int vEdge = nEdge[nodeV]; vEdge >= 0; vEdge--)
		for (int curNode = k-1; curNode >= 0; curNode--) for (int vNode = k-1; vNode >= 1; vNode--){
			int sumNode = curNode + vNode;
			if (sumNode<1||sumNode>k) continue;
			int sumEdge = curEdge + (vEdge + 1);
			dp[nodeU][sumEdge][sumNode] += dp[nodeU][curEdge][curNode]*dp[nodeV][vEdge][vNode];
		}
		nEdge[nodeU] += nEdge[nodeV] + 1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> k >> a >> b;
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,-1);
	
	long long int res = 0;
	for (int i = a; i <= b; i++){
		for (int j = 1; j <= n; j++){
			res += dp[j][i][k];
		}
	}
	cout << res;
	return 0;
}
