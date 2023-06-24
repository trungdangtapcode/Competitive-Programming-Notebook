#include <bits/stdc++.h>
using namespace std;
typedef pair<int, long int> id;
vector<vector<int>> edge (3005);
vector<int> low; 
vector<bool> visited;
int n, m;

using namespace std;

void bfs(int x){
	vector<bool> visitedX;
	visitedX.assign(n,false);
	queue<int> q;
	q.push(x);
	
	while (!q.empty()){
		int nodeU = q.front();
		q.pop();
		
		if (visitedX[nodeU]) continue;
		for (auto& it: edge[nodeU]){
			int nodeV = it;
			
			if (!visitedX[nodeV]){
				low[nodeV] = low[nodeU];
				q.push(nodeV);
			}
		}
		visitedX[nodeU] = true;
		visited[nodeU] = true;
	}
}

void solve(){
	cin >> n >> m;
	
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a-1].push_back(b-1);
	}
	
	visited.assign(n,false); //visited[0] = true;
	low.assign(n,-1); for (int i = 0; i < n; i++) low[i] = i;
	//bfs(0);
	//for (int i = 0; i < n; i++) cout << low[i] << " ";
	for (int i = 0; i < n; i++) if (!visited[i]) bfs(i);
	//for (int i = 0; i < n; i++) cout << low[i] << " ";
	set<int> set_low (low.begin(),low.end());
	cout << set_low.size();
}

int main(){
	solve();
	
	return 0;
}
