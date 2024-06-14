#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 1e6+5;
int n, a[maxN], used[maxN], cmp[maxN], m, sum[maxN], sz[maxN];
vector<int> edge[maxN], redge[maxN], bedge[maxN];
vector<int> order;	
ii f[maxN];
void dfs1(int v) {
    used[v] = true;

    for (auto u : edge[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}
void dfs2(int v, int x) {
    used[v] = true;
    cmp[v] = x;

    for (auto u : redge[v])
        if (!used[u])
            dfs2(u,x);
}
void dfs3(int u){
	if (f[u]!=ii{-1,-1}) return;
	f[u] = {sz[u],sum[u]};
	for (int v: bedge[u]){
		dfs3(v);
		f[u] = max(f[u],{f[v].first+sz[u],f[v].second+sum[u]});
	}
}
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) edge[i].clear(), redge[i].clear(), bedge[i].clear();
	for (int i = 1; i<= n; i++) cin >> a[i];
	for (int i = 1, u,v ; i<= m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		redge[v].push_back(u);
	}
	for (int i = 1; i<= n; i++) used[i] = 0;
	order.clear();
	for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);
    for (int i = 1; i<= n; i++) used[i] = 0;
    reverse(order.begin(),order.end());
    int x = 0;
    for (int u: order){
    	if (!used[u]){
    		dfs2(u,++x);
		}
	}
	for (int i = 1; i <= x; i++) sum[i] = sz[i] = 0;
	for (int i = 1; i <= n; i++){
		sum[cmp[i]] -= a[i];
		sz[cmp[i]]++;
		for (int v: edge[i]) if (cmp[i]!=cmp[v]) bedge[cmp[i]].push_back(cmp[v]);
	}
	for (int i = 1; i <= x; i++) f[i] = {-1,-1};
	for (int i = 1; i <= x; i++){
//		cout << "cmp " << i << " " << sum[i] << " " << sz[i] << "\n";
		dfs3(i);
	}
	ii res = {-1,-1};
	for (int i = 1; i <= x; i++) res = max(res,f[i]);
	cout << res.first << " " << -res.second << "\n";
//	for (int i = 1; i <= n; i++) cout << i << ": " << f[i].first << " " << f[i].second << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
