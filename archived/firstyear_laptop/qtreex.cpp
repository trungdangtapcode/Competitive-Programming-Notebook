#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e4+5;
typedef pair<int,int> ii;
int n, par[maxN], sz[maxN], d[maxN], w[maxN], child[maxN];
vector<ii> edge[maxN];
void dfs(int u, int p){
	par[u] = p;
	sz[u] = 1;
	d[u] = d[p]+1;
	for (auto it: edge[u]){
		int v = it.first, idx = it.second;
		if (v==p) continue;
		child[idx] = v;
		dfs(v,u);
		sz[u] += sz[v];
	}
}

int chainHead[maxN], chainID[maxN], pos[maxN], arr[maxN];
int curChain = 1, curPos = 1;
void hld(int u, int p){
	if (!chainHead[curChain]){
		chainHead[curChain] = u;
	}
	chainID[u] = curChain;
	pos[u] = curPos;
	arr[curPos] = u;
	curPos++;
	int nxt = 0;
	for (auto it: edge[u]){
		int v = it.first;
		if (v==p) continue;
		if (nxt==0||sz[v]>sz[nxt]) nxt = v;
	}
	if (nxt) hld(nxt,u);
	for (auto it: edge[u]){
		int v = it.first;
		if (v==p||v==nxt) continue;
		curChain++;
		hld(v,u);
	}
}
int lca(int u, int v){
	while (chainID[u]!=chainID[v]){
		if (chainID[u]>chainID[v]){
			u = par[chainHead[chainID[u]]];
		} else {
			v = par[chainHead[chainID[v]]];
		}
	}
	if (d[u]>d[v]) return v;
	return u;
}

int lazy[maxN*4];
ii val[maxN*4];
void down(int k){
	if (!lazy[k]) return;
	val[2*k] = {-val[2*k].second,-val[2*k].first};
	val[2*k+1] = {-val[2*k+1].second,-val[2*k+1].first}; //=))
	lazy[2*k] ^= 1;
	lazy[2*k+1] ^= 1;
	lazy[k] = 0;
}
void updt1(int k, int l, int r, int u, int v){
	if (l>u||r<u) return;
	if (l==r){
		val[k] = {v,v};
		return;
	}
	int m = (l+r)/2;
	down(k);
	updt1(2*k,l,m,u,v);
	updt1(2*k+1,m+1,r,u,v);
	val[k].first = min(val[2*k].first, val[2*k+1].first);
	val[k].second = max(val[2*k].second, val[2*k+1].second);
//	assert(val[k].first<=val[k].second);
}
void updt2(int k, int l, int r, int u, int v){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] = {-val[k].second,-val[k].first};
		lazy[k] ^= 1;
		return;
	}
//	assert(val[k].first<=val[k].second);
	int m = (l+r)/2;
	down(k);
	updt2(2*k,l,m,u,v);
	updt2(2*k+1,m+1,r,u,v);
	val[k].first = min(val[2*k].first, val[2*k+1].first);
	val[k].second = max(val[2*k].second, val[2*k+1].second);
//	assert(val[k].first<=val[k].second);
}
int gett(int k, int l, int r, int u, int v){
	//error => down(k) wrong a 2*k update for 2*k+1
	assert(val[k].first<=val[k].second);
	if (l>v||r<u) return -1e9;
	if (u<=l&&r<=v) return val[k].second;
	int m = (l+r)/2;
	down(k);
	return max(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}

void update1(int idx, int val){
	int v = child[idx];
	updt1(1,1,n,pos[v],val);
}
void update2(int u, int v){
	int z = lca(u,v);
	while (chainID[u]!=chainID[z]){
		updt2(1,1,n,pos[chainHead[chainID[u]]],pos[u]);
		u = par[chainHead[chainID[u]]];
	}
	while (chainID[v]!=chainID[z]){
		updt2(1,1,n,pos[chainHead[chainID[v]]],pos[v]);
		v = par[chainHead[chainID[v]]];
	}
	if (u==v) return;
	if (d[u]>d[v]) updt2(1,1,n,pos[v]+1,pos[u]);
	else updt2(1,1,n,pos[u]+1,pos[v]);
}
int query(int u, int v){
	int z = lca(u,v);
	int res = -1e9;
	//wrong LCA (>->!=) so while forever (while reasoning) 
	while (chainID[u]!=chainID[z]){
		res = max(res,gett(1,1,n,pos[chainHead[chainID[u]]],pos[u]));
		u = par[chainHead[chainID[u]]];
	}
	while (chainID[v]!=chainID[z]){
		res = max(res,gett(1,1,n,pos[chainHead[chainID[v]]],pos[v]));
		v = par[chainHead[chainID[v]]];
	}
	assert(u==z||v==z);
	if (u==v) return res;
	if (d[u]>d[v]) res = max(res,gett(1,1,n,pos[v]+1,pos[u]));
	else res = max(res,gett(1,1,n,pos[u]+1,pos[v]));
	return res;
}


void rs(){
	for (int i = 1; i <= n; i++) edge[i].clear(), chainHead[i] = 0;
	curChain = curPos = 1;
	for (int i = 1; i <= 4*n; i++){
		val[i] = {0,0};
		lazy[i] = 0;
	}
}

void solve(){
	cin >> n;
	rs();
	for (int i = 1; i < n; i++){
		int u, v, c;
		cin >> u >> v >> c;
		w[i] = c;
		edge[u].push_back({v,i});
		edge[v].push_back({u,i});
	}
	dfs(1,0);
	hld(1,0);
	for (int i = 1; i < n; i++){
		update1(i,w[i]);
	}
	
//	cout << lca(4,5) << "\n";

//	for (int i = 1; i <= n; i++){
//		int a; cin >> a;
//		updt1(1,1,n,i,a);
//	}
//	updt2(1,1,n,4,5);
//	updt2(1,1,n,4,5);
//	auto tmp = gett(1,1,n,1,n);
//	cout <<  tmp << "\n";

	
//	update2(1,5);
//	for (int i = 1; i <= n; i++) cout << gett(1,1,n,i,i) << " "; cout << "\n";
//	for (int i = 1; i <= n; i++) cout << arr[i] << " "; cout << "\n";

	while (true){
		string s;
		cin >> s;
		if (s=="QUERY"){
			int a, b;
			cin >> a >> b;
			int res = query(a, b);
			cout << (res==-1e9?0:res) << "\n";
		} else if (s=="CHANGE"){
			int i, v;
			cin >> i >> v;
			update1(i,v);
		} else if (s=="NEGATE"){
			int a, b;
			cin >> a >> b;
			update2(a,b);
		} else {
			assert(s=="DONE");
			break;
		}
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

