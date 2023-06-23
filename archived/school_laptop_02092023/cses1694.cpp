#include<bits/stdc++.h>

using namespace std;
int n, m;
bool visited[505];
long long int c[505][505], f[505][505];
vector<int> edge[505], unedge[505]; 

long long int dfs(int u, long long int flow){
	visited[u] = true;
	if (u==n){
		return flow;
	}
	for (int v: edge[u]) if (!visited[v]){
		if (c[u][v]>f[u][v]){
			long long int x = dfs(v,min(flow,c[u][v]-f[u][v]));
			if (visited[n]){
				f[u][v] += x;
				return x;
			}
		}
	}
	for (int v: unedge[u]) if (!visited[v]){
		if (f[v][u]){
			long long int x = dfs(v,min(flow,f[v][u]));
			if (visited[n]){
				f[v][u] -= x;
				return x;
			}
		}
	}
	return flow;
}

int main(){
	
	cin >> n >> m;
	for (int i = 0, u, v, cx; i < m; i++){
		cin >> u >> v >> cx;
		edge[u].push_back(v);
		c[u][v] += cx;
		unedge[v].push_back(u);
	}
	long long int res = 0;
	do{
		memset(visited,false,sizeof(visited));
		long long int x = dfs(1,1e18);
		if (visited[n]) res += x;
		else break;
	} while (true);
	cout << res << endl;
	
	return 0;
}
