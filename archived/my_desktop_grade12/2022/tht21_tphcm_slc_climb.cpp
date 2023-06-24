#include<bits/stdc++.h>

using namespace std;
#define ld long double
#define int long long
typedef pair<int,int> ii;
typedef pair<ld,ii> dii;


const int maxN = 100005;
int n, m, x[maxN], y[maxN], prv[maxN], nxt[maxN], connected[maxN];

ld eval(int i, int j){
	return (ld)(y[j]-y[i])/(x[j]-x[i]);
}

int jump[maxN][20], d[maxN];
vector<int> edge[maxN];
void dfs(int u){
	for (int v: edge[u]){
		d[v] = d[u]+1;
		dfs(v);	
	}
}
int lca(int u, int v){
	if (d[u]>d[v]) swap(u,v);
	for (int i = 19; i >= 0; i--) if (d[jump[v][i]]>=d[u]) v = jump[v][i];
	for (int i = 19; i >= 0; i--) if (jump[v][i]!=jump[u][i]) u = jump[u][i], v = jump[v][i];
	while (u!=v) u = jump[u][0], v = jump[v][0];
	return u;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	cin >> m;
	
	priority_queue<dii> pq;
	for (int i = 1; i < n; i++){
		pq.push({eval(i,i+1),{i,-(i+1)}});		
	}
	for (int i = 1; i <= n; i++){
		prv[i] = i-1;
		nxt[i] = i+1;
		connected[i] = 0;
	}
	while (pq.size()){
		int u = pq.top().second.first, v = -pq.top().second.second;
		pq.pop();
		if (connected[u]) continue;
		connected[u] = v;
		prv[nxt[u]] = prv[u];
		nxt[prv[u]] = nxt[u];
		if (prv[u]==0) continue;
		pq.push({eval(prv[u],v),{prv[u],-v}});
	}
	
	for (int i = 1; i <= n; i++){
//		cout << i << " -> " << connected[i] << "\n";
		jump[i][0] = connected[i];
		edge[connected[i]].push_back(i);
	}
	for (int i = 1; i < 20; i++){
		for (int u = 1; u <= n; u++) jump[u][i] = jump[jump[u][i-1]][i-1];
	}
	d[n] = 1;
	dfs(n);
	
	while (m--){
		int a, b;
		cin >> a >> b;
		cout << lca(a,b) << " ";
	}
	
	return 0;
}
