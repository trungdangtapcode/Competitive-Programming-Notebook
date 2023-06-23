#include<bits/stdc++.h>

using namespace std;

struct myEdge{
	int u, v, cap, flow;
};

struct Flow{
	int n, s, t, d[10005], ptr[10005];
	vector<myEdge> edgelist;
	vector<int> edge[10005];
	Flow(int _n, int _s, int _t){
		n = _n;
		s = _s;
		t = _t;
	}
	void addEdge(int u, int v, int c){
		edge[u].push_back(edgelist.size()); edgelist.push_back(myEdge({u,v,c,0}));
		edge[v].push_back(edgelist.size()); edgelist.push_back(myEdge({v,u,0,0}));
	}
	int bfs(){
		for (int i = 1; i<= n; i++) d[i] = -1;
		d[s] = 0;
		queue<int> q;
		q.push(s);
		while (q.size()){
			int u = q.front(); q.pop();
			for (int id: edge[u]){
				auto& it = edgelist[id];
				if (d[it.v]==-1&&it.cap>it.flow) q.push(it.v), d[it.v] = d[u] + 1;
			}
		}
		return (d[t]!=-1);
	}
	int dfs(int u, int val){
		if (!val) return 0;
		if (u==t) return val;
		for (; ptr[u] < edge[u].size(); ptr[u]++){
			auto& it = edgelist[edge[u][ptr[u]]], &it_rev = edgelist[edge[u][ptr[u]]^1];;
			if (d[it.v]!=d[u]+1) continue;
			int new_val = dfs(it.v,min(val,it.cap-it.flow));
			if (!new_val) continue;
			it.flow += new_val;
			it_rev.flow -= new_val;
			return new_val; 
		}
		return 0;
	}
	int maxFlow(){
		int res = 0;
		while (bfs()){
			for (int i = 1; i <= n; i++) ptr[i] = 0;
			while (true){
				int val = dfs(s,1e9);
				if (!val) break;
				res += val;
			}
		}
		return res;
	}
	
	
};

int main(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	Flow graph(n,s,t);
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		graph.addEdge(u,v,c); 
	}
	cout << graph.maxFlow();
	return 0;
}
