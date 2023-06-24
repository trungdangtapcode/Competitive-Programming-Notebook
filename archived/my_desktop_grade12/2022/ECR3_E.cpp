#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> p4i;
int n, m, d[200005];
vector<p4i> edgelist;
vector<ii> edge[200005];
ii par[200005][20];
void dfs(int p, int u, int c = -1e9){
	par[u][0] = {p,c};
	d[u] = d[p] + 1;
	for (int i =1; i < 20; i++) par[u][i] = {
		par[par[u][i-1].first][i-1].first,
		max(par[u][i-1].second,par[par[u][i-1].first][i-1].second)
	};
	for (auto it: edge[u]){
		int v = it.first, c = it.second;
		if (v==p) continue;
		dfs(u,v,c);
	}
}

int cha[200005];
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pu] = pv;
	return true;
}
int lca(int u, int v){
//	cout << "LCA of " << u << " and " << v << " is ";
	if (d[u]>d[v]) swap(u,v);
	int res = -1e9;
	for (int i = 19; i >= 0; i--) if (d[par[v][i].first]>=d[u]){
		res = max(res,par[v][i].second);
		v = par[v][i].first;
	}
	for (int i = 19; i >= 0; i--) if (par[u][i].first!=par[v][i].first){
		res = max(res,max(par[u][i].second,par[v][i].second));
		u = par[u][i].first, v=  par[v][i].first;
	}
	while (u!=v){
		res = max(res,max(par[u][0].second,par[v][0].second));
		u = par[u][0].first, v=  par[v][0].first;
	}
//	cout << u << "\n";
	return res;
}

long long res[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cha[i] = i;
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		edgelist.push_back({{c,i},{u,v}});
	}
	sort(edgelist.begin(),edgelist.end());
	long long sum = 0;
	for (auto it: edgelist){
		int u = it.second.first, v= it.second.second, c = it.first.first;
		if (hop(u,v)){
			edge[u].push_back({v,c});
			edge[v].push_back({u,c});
			sum += c;
		}
	}
	dfs(1,1);
	for (auto it: edgelist){
		int u = it.second.first, v = it.second.second, c = it.first.first, idx = it.first.second;
		res[idx] = sum-lca(u,v)+c;
	}
	for (int i =0; i < m; i++) cout << res[i] << "\n";
	
	return 0;
}
