#include <bits/stdc++.h>

using namespace std;

int connectPoint(int n, std::vector<std::vector<int>> G){
	auto check = [&](int k){
		bool visited[1005];
		memset(visited,false,sizeof(visited));
		queue<int> q;
		q.push(0);
		visited[0] = true;
		while (!q.empty()){
			int u = q.front(); q.pop();
			for (int v = 0; v < n; v++) if (!visited[v]){
				if ((G[u][0]-G[v][0])*(G[u][0]-G[v][0])+(G[u][1]-G[v][1])*(G[u][1]-G[v][1])<=k) q.push(v), visited[v] = true; 
			}	
		}
		for (int i = 0; i < n; i++) if (!visited[i]) return false;
		return true;
	};
	int l = 0, h = 1250e6, m, res;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			h = m-1;
			res = m;
		} else l = m+1;
	}
	return res;
}

int n;
vector<vector<int>> g;
int main(){
	cin >> n;
	g.resize(n,vector<int>(2));
	for (int i = 0; i < n; i++) cin >> g[i][0] >> g[i][1];
	cout << connectPoint(n,g);
	
	return 0;
}

/*
int connectPoint(int n, std::vector<std::vector<int>> G){
	auto check = [&](int k){
		bool visited[1005];
		memset(visited,false,sizeof(visited));
		queue<int> q;
		q.push(0);
		visited[0] = true;
		while (!q.empty()){
			int u = q.front(); q.pop();
			for (int v = 0; v < n; v++) if ((G[u][0]-G[v][0])*(G[u][0]-G[v][0])+(G[u][1]-G[v][1])*(G[u][1]-G[v][1])<=k){
				if (!visited[v]) q.push(v), visited[v] = true; //better loop than visted[u] outside
	//			cout << u << " -> " << v << endl;
			}	
		}
		for (int i = 0; i < n; i++) if (!visited[i]) return false;
		return true;
	};
//	return (check(17)?69:-69);
	int l = 0, h = 1250e6, m, res;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			h = m-1;
			res = m;
		} else l = m+1;
	}
	return res;
}
*/
