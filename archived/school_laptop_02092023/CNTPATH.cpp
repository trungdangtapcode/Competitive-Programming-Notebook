#include<bits/stdc++.h>
#define int	long long 

using namespace std;
int f[100005]; //duong di di qua cha[i] ko qua i
int g[100005]; //duong di bat dau tu cha[i] ko qua i
int s1[100005]; //duong di bat dau tu i
int s2[100005]; //duong di di qua i (i khac 2 dau mut) => di qua i = s1 + s2
int preff[100005]; //prefix sum cua f[root->i]
int prefg[100005]; //prefix sum cua s1[root->i]
int par[100005][25], d[100005];
vector<int> edge[100005];
int n, q;

void dfs1(int p, int u){
	d[u] = d[p] + 1;
	par[u][0] = p;
	s1[u] = 1;
	for (int v: edge[u]) if (v!=p){
		dfs1(u,v);
		s2[u] += (s1[u]-1)*s1[v];
		s1[u] += s1[v];
	}
}
void dfs2(int p, int u){
	if (u!=1) f[u] = s2[p] - (s1[p]-1-s1[u])*s1[u] +  (s1[p]-s1[u]);
	if (u!=1) g[u] = s1[p] - s1[u];
	preff[u] = preff[p] + f[u];
	prefg[u] = prefg[p] + g[u];
	for (int v: edge[u]) if (v!=p){
		dfs2(u,v);
	}
}
int lca(int x, int y){
	if (d[x]>d[y]) swap(x,y);
	while (d[x]<d[y]) y = par[y][0];
	while (x!=y) x = par[x][0], y = par[y][0];
	return x;
}
int solve(int x, int y){
	if (x==y) return (s1[x]+s2[x])*(prefg[x]+1);
	if (d[x]>d[y]) swap(x,y);
	int z = lca(x,y), xx = x, yy = y;
	while (d[par[xx][0]]>d[z]) xx = par[xx][0];
	while (d[par[yy][0]]>d[z]) yy = par[yy][0];
	int res = preff[x]-preff[xx]+preff[y]-preff[yy];
//	cout << x << " " << xx << endl;
	if (xx!=z) res += s2[z]-(s1[z]-1-s1[xx]-s1[yy])*(s1[xx]+s1[yy])-s1[xx]*s1[yy] + (s1[z]-s1[xx]-s1[yy])*(prefg[z]+1),
			res += s1[x]+s2[x]+s1[y]+s2[y];
	else res += s2[xx]-(s1[xx]-1-s1[yy])*s1[yy]+(s1[xx]-s1[yy])*(prefg[xx]+1),
			res += s1[y] + s2[y];
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,1);
	dfs2(1,1);
//	f[1] = 0;
	
//	cout << "s1: "; for (int i = 1; i <= n; i++) cout << s1[i] << " "; cout << endl;
//	cout << "s2: "; for (int i = 1; i <= n; i++) cout << s2[i] << " "; cout << endl;
//	cout << "f: "; for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << endl;
//	cout << "g: "; for (int i = 1; i <= n; i++) cout << g[i] << " "; cout << endl;
//	cout << "preff: "; for (int i = 1; i <= n; i++) cout << preff[i] << " "; cout << endl;
//	cout << "prefg: "; for (int i = 1; i <= n; i++) cout << prefg[i] << " "; cout << endl;
//	cout << "d: "; for (int i = 1; i <= n; i++) cout << d[i] << " ";  cout << endl;
//	cout << solve(3,5);
	while (q--){
		int x, y;
		cin >> x >> y;
		cout << solve(x,y) << "\n";
	}
	
	
	return 0;
}
