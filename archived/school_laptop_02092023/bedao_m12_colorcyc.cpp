#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> edge[200005];
bool visited[200005], dfsed[200005];
vector<pair<int,int>> edgelist;


bool dfs(int u){
	visited[u] = dfsed[u] = true;
	for (int v: edge[u]){
		if (dfsed[v]&&!visited[v]){
			visited[u] = false;
			return true;
		}
		if (visited[v]){
			visited[u] = false;
			return false;
		}
		if (!dfs(v)){
			visited[u] = false; 
			return false;	
		}
	}
	visited[u] = false; return true;
}

int main(){
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edgelist.push_back({u,v});
	}
	bool mot_mau = true;
	for (int i = 1; i <= n; i++) if (!dfsed[i]){
		if (!dfs(i)) mot_mau = false;
	}
	if (m==0){
		cout << 0;
	} else if (mot_mau){
		cout << 1 << "\n";
		for (int i = 0; i < m; i++) cout << 1 << "\n";
	} else {
		cout << 2 << "\n";
		for (auto it: edgelist){
			if (it.first<it.second) cout << 1 << "\n"; else cout << 2 << "\n";
		}
	}
	
	return 0;
}

