#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int f[100005][30];
vector<int> edge[1000005];
int n, res2[1000005];
void dfs(int p, int u){
	for (int i = 1; i <= 30; i++) f[u][i] = i;
	for (int v: edge[u]) if (v!=p){
		dfs(u,v);
		for (int i = 1; i <= 30; i++){
			int mmin = 1e9;
			for (int j = 1; j <= 30; j++) if (j!=i) mmin = min(mmin,f[v][j]);
			f[u][i] += mmin;
		}
	}
}
void trace(int p, int u, int c){
	res2[u] = c;
	for (int v: edge[u]) if (v!=p){
		ii mmin = {1e9,0};
		for (int i = 1; i <= 30; i++) if (i!=c) mmin = min(mmin,{f[v][i],i});
		trace(u,v,mmin.second);
	}
}

int main(){
	
	cin >> n;
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0,1);
	ii res = {1e9,0};
	for (int i = 1; i <= 30; i++) res = min(res,{f[1][i],i});
	cout << res.first << "\n";
	trace(0,1,res.second);
	for (int i = 1; i <= n; i++) cout << res2[i] << "\n";	
	
	return 0;
}
