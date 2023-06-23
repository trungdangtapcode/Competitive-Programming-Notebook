#include<bits/stdc++.h>

using namespace std;
int a, b, n, d[100005], d1[100005], d2[100005], q;
long long c1[100005], c2[100005];
vector<int> edge[100005];
void dfs(int u){
	for (int v: edge[u]) if (d[v]>d[u]+1){
		d[v] = d[u] + 1;
		dfs(v);
	}
}
int cost(int u, int v){
	return (d[u]>d[v]?a:b);
}
void dfs1(int u){
	for (int v: edge[u]) if (d1[v]>d1[u]+1){
		d1[v] = d1[u] + 1;
		c1[v] = c1[u] + 1ll*d1[v]*cost(u,v);
		dfs1(v);
	}
}
void dfs2(int u){
	for (int v: edge[u]) if (d2[v]>d2[u]+1){
		d2[v] = d2[u] + 1;
		c2[v] = c2[u] + 1ll*d2[v]*cost(u,v);
		dfs2(v);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("MEETING.INP","r",stdin);
	freopen("MEETING.OUT","w",stdout);
	cin >> n >> q;
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	while (q--){
		int s, u,v ;
		cin >> s >> u >> v >> a >> b;
		for (int i = 1; i <= n; i++) d[i] = d1[i] = d2[i] = 1e9;
		d[s] = d1[u] = d2[v] = c1[u] = c2[v] = 0;
		dfs(s);
		dfs1(u);
		dfs2(v);
		long long res = 1e18;
		for (int i= 1; i<= n; i++) res = min(res,c1[i]+c2[i]);
		cout <<res << "\n";
//		for (int i = 1; i <= n; i++) cout << c1[i] << " ";
	}
	
	
	return 0;
}
