#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m;
vector<int> edge[100005]; //big_edge[100005];
int big[100005], big_deg[100005];
queue<ii> edge_queue;
stack<int> big_stack;

int low[100005], tin[100005], timer;
void dfs1(int u, int p){
	tin[u] = low[u] = ++timer;
	for (int v: edge[u]) if (v!=p){
		if (tin[v]!=0){
			low[u] = min(low[u],tin[v]);
		} else {
			dfs1(v,u);
			low[u] = min(low[u],low[v]);
			big_stack.push(v);
			if (low[v]>tin[u]){
				edge_queue.push({u,v});
				while (big_stack.top()!=v){
					int x = big_stack.top();
					big[x] = v;
					big_stack.pop();
				}
				big_stack.pop();
			}	 
			
		}
	}
	
}

int main(){
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) big[i] = i;
	dfs1(1,0);
	while (!big_stack.empty()){
		int x = big_stack.top();
		big[x] = 1;
		big_stack.pop();
	}
	while (!edge_queue.empty()){
		int u = edge_queue.front().first, v = edge_queue.front().second;
		edge_queue.pop();
//		big_edge[big[u]].push_back(big[v]);
//		big_edge[big[v]].push_back(big[u]);
		big_deg[big[u]]++;
		big_deg[big[v]]++;
//		cout << u << " " << v << endl;;
	}
//	for (int i = 1; i <= n; i++) cout << i << " -> " << big[i] << endl;
	int res = 0;
	for (int i = 1; i <= n; i++) if (big_deg[i]==1) res++;
//	for (int i = 1; i <= n; i++) cout << big[i] << " "; cout << endl;
	if (res%2) cout << res/2+1;
	else cout << res/2; 
	
	return 0;
}
