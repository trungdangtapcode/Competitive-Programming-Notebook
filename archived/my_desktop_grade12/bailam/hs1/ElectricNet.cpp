#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<int,int>> edge[100005];
vector<pair<int,pair<int,int>>> edgelist;
pair<int,int> up[100005][20];
int deep[100005];

int cha[100005];
int timcha(int u){
	if (cha[u]==u) return u;
	return (cha[u]=timcha(cha[u]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pv] = pu;
	return true;
}

void dfs(int p, int u, int c){
	deep[u] = deep[p]+1;
	up[u][0].second = c;
	up[u][0].first = p;
	for (int i = 1; i <= 19; i++){
		up[u][i].first = up[up[u][i-1].first][i-1].first;
		up[u][i].second = min(up[u][i-1].second,up[up[u][i-1].first][i-1].second);
	}
	for (auto it: edge[u]){
		int v = it.first, c = it.second;
		if (v==p) continue;
		dfs(u,v,c);
	}
}

int lca(int u, int v){
	int res = 1e9;
	for (int i = 19; i >= 0; i--) if (deep[up[u][i].first]>=deep[v]) 
		res = min(res,up[u][i].second), u = up[u][i].first;
	for (int i = 19; i >= 0; i--) if (deep[up[v][i].first]>=deep[u])
		res = min(res,up[v][i].second), v = up[v][i].first;
	for (int i = 19; i >= 0; i--) if (up[u][i]!=up[v][i]) 
		res = min(res,min(up[u][i].second,up[v][i].second)), 
		u = up[u][i].first, v = up[v][i].first;
	while (u!=v) 
		res = min(res,min(up[u][0].second,up[v][0].second)),
		u = up[u][0].first, v = up[v][0].first;
	return res;
}

int main(){
	
	
	cin >> n >> m;
	for (int i = 0, x, y, c; i < m; i++){
		cin >> x >> y >> c;
		edgelist.push_back({c,{x,y}});
	}
	for (int i = 1; i <= n; i++) cha[i] = i;
	sort(edgelist.begin(),edgelist.end());
	for (int i = m-1; i >= 0; i--){
		int u = edgelist[i].second.first, v = edgelist[i].second.second, c = edgelist[i].first;
		if (hop(u,v)){
			edge[u].push_back({v,c});
			edge[v].push_back({u,c});
		}
	}
	deep[0] = 0; //nothing
	dfs(0,1,0);
	for (int i = 0; i < 4; i++){
		cout << i << ": ";
		for (int j = 1; j <= n; j++) cout << " (" << up[j][i].first << "," << up[j][i].second << ") ";
		cout << endl;
	}
//	cout << lca(4,6);
	long long int res = 0;
	for (int i = 0, u, v, c; i < m; i++){
		u = edgelist[i].second.first, v = edgelist[i].second.second, c = edgelist[i].first;
		cout << u << " " << v << " " << c << "->" << lca(u,v) << endl;
		res += lca(u,v)-c;
	}
	cout << res;
	
	return 0;
}
