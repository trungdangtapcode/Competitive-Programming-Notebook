#include<bits/stdc++.h>
//it is a MIRROR graph
//is all v is same is mirror or u has no child it is mirror
//there no child: it is brance but we dfs 2 times

using namespace std;
const int base = 31, mod = 1e9+7;
//hash: f[v] = 0 it's a leaf (default if not leaf it will be update), 
//f[v] = hash(f[mirror child], cnt child), f[v] = -1 wrong mirror
//s[v]: set of f[mirror] and count. if have more than 2 distinct f[mirror] it's wrong
//dfs1 + dfs2 = ancestor + child. inclusion

vector<int> edge[100005];
int n, f[100005], res = -1;
map<int,int> s[100005];

void calc(int u){ //calculating f[u]
	if (s[u].size()==0){
		f[u] = 0;
		return;
	}
	if (s[u].size()>1){
		f[u] = -1;
		return;
	}
	auto it = s[u].begin();
	if (it->first==-1){
		f[u] = -1;
		return;
	}
	f[u] = (1ll*base*it->first+it->second)%mod; //f[] = hash of the subtree from 1 
}

void dfs1(int u, int p = -1){
	for (int v: edge[u]) if (v!=p){
		dfs1(v,u);
		s[u][f[v]]++;
	}
	calc(u);
}
void dfs2(int u, int p = -1){
	if (p!=-1){
		s[u][f[p]]++;
		calc(u);
	}
	if (f[u]!=-1){
		res = u;
	}
	for (int v: edge[u]) if (v!=p){
		s[u][f[v]]--; //exclusion
		if (s[u][f[v]]==0) s[u].erase(f[v]);
		calc(u);
		dfs2(v,u);
		s[u][f[v]]++;
		calc(u);
	}
	if (p!=-1){
		s[u][f[p]]--;
		if (s[u][f[p]]==0) s[u].erase(f[p]);
		calc(u);
	}
}

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1);
	dfs2(1);
	cout << res;
	return 0;
}
