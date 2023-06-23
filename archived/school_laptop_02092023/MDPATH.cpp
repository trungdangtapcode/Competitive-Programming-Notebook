#include<bits/stdc++.h>

using namespace std;
int trace[100005], n, m, x, y;
vector<int> edge[100005];

void dfs(int u){
	for (int v: edge[u]) if (trace[v]==-1){
		trace[v] = u;
		dfs(v);
	}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) trace[i] = -1;
	for (int i = 1, u, v; i <= m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}	
	for (int i = 1; i <= n; i++) sort(edge[i].begin(),edge[i].end());
	cin >> x >> y;
	trace[x] = 0;
	dfs(x);
	stack<int> res;
	if (trace[y]==-1) return 0;
	do {
		res.push(y);
		y = trace[y];
	} while (y>0);
	while (!res.empty()){
		cout << res.top() << " ";
		res.pop();
	}
	
	return 0;
}
