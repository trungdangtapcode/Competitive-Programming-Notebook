#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int dp[5005][5005], a[5005], n;
vector<int> edge[5005], child[5005];
int leaf[5005], st = 1;
void dfs(int p, int u){
	if (edge[u].size()==1) leaf[u] = 1;
//	isLeaf[u] = true;
	for (int v: edge[u]) if (v!=p){
		child[u].push_back(v);
		dfs(u,v);
		leaf[u] += leaf[v];
//		isLeaf[v] = false;
	}
}
void calc(int p, int u){
	if (child[u].size()==0){
		dp[u][0] = abs(a[u]);
		dp[u][1] = abs(a[u]-1);
		return;
	}
	for (int v: child[u]){
		calc(u,v);	
	}
	for (int i = 0; i <= leaf[u]; i++){
		int l = child[u][0];
//		if (edge[u][0]==p) l = edge[u][1];
		if (child[u].size()==1){
			dp[u][i] = dp[l][i] + abs(a[u]-i);
			continue;
		}
		int r = child[u][1];
//		if (edge[u][0]==p||edge[u][1]==p) r = edge[u][2];
//		cout << u << " " << l << " " << r << endl; 
		for (int j = 0; j <= i; j++) dp[u][i] = min(dp[u][i],dp[l][j]+dp[r][i-j]+abs(a[u]-i));
		}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n==1){
		cout << min(abs(a[1]),abs(a[1]-1));
		return 0;
	}
	if (n==2){
		cout << min(abs(a[1])+abs(a[2]),abs(a[1]-1)+abs(a[2]-1));
		return 0; 
	}
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
//	for (st = 1; st <= n; st++) if (edge[st].size()==2) break;
	dfs(-1,st);
	memset(dp,1,sizeof(dp));
	calc(-1,st);
	int res = 1e9;
	
//	cout <<  "st = " << st << endl;
//	for (int i = 1; i <= n; i++){
//		cout << i << ":\n";
//		cout << leaf[i] << endl;
//		for (int j = 0; j < 5; j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	
	for (int i = 0; i <= leaf[st]; i++) res = min(res,dp[st][i]);
	cout <<res;
	return 0;
}
