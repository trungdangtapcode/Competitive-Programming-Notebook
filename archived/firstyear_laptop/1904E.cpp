#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;

int n, q, x[maxN], res[maxN];
vector<int> vx[maxN];

vector<int> edge[maxN], node_query[maxN];
int dist[maxN], to_root[maxN], root = 1;

int tin[maxN], tout[maxN], timer, tin_inv[maxN];

long long val[maxN*4], lazy[maxN*4];

void build(int k, int l, int r){
	if (l==r){
		val[k] = dist[tin_inv[l]];
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = max(val[2*k],val[2*k+1]);
}
void down(int k){
	if (lazy[k]==0) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	val[2*k] += lazy[k];
	val[2*k+1] += lazy[k];
	lazy[k] = 0;
}
void updt(int k, int l, int r, int u, int v, int x){
	if (u>r||v<l) return;
	if (u<=l&&r<=v){
		val[k] += x;
		lazy[k] += x;
		return;
	}
	int m = (l+r)/2;
	down(k);
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = max(val[2*k],val[2*k+1]);
}
int gett(int k, int l, int r, int u, int v){
	if (u>r||v<l) return -1;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	down(k);
	return max(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}

void dfs(int u, int p){
	tin[u] = ++timer;
	tin_inv[tin[u]] = u;
	to_root[u] = -1;
	for (int v: edge[u]) if (v!=p){
		dist[v] = dist[u] + 1;
		dfs(v,u);
	}
	tout[u] = timer;
}

void print(int u){
	cout << u << ": ";
	for (int i = 1; i <= n; i++) cout << gett(1,1,n,tin[i],tin[i]) << " ";
	cout << "\n";
}

void dfs2(int u, int p){
	
	for (int idx: node_query[u]){
//		cout << " + query " << idx << "  \n";
		for (int y: vx[idx]){
			if (to_root[y]!=-1){
				int z = to_root[y];
				updt(1,1,n,1,n,-1e6);
				updt(1,1,n,tin[z],tout[z],1e6);
//				cout << "a " << y << "->" << z << "\n";
			} else {
				updt(1,1,n,tin[y],tout[y],-1e6);
//				cout << "d " << y << "\n";
			}
		}
//		print(u);
		res[idx] = gett(1,1,n,1,n);
		for (int y: vx[idx]){
			if (to_root[y]!=-1){
				int z = to_root[y];
				updt(1,1,n,1,n,1e6);
				updt(1,1,n,tin[z],tout[z],-1e6);
			} else {
				updt(1,1,n,tin[y],tout[y],1e6);
			}
		}
//		print(u);
	}
	
	for (int v: edge[u]) if (v!=p){
		updt(1,1,n,1,n,1);
		updt(1,1,n,tin[v],tout[v],-2);
		to_root[u] = v;
		root = v;
		dfs2(v,u);
		to_root[u] = -1;
		root = u;
		updt(1,1,n,tin[v],tout[v],+2);
		updt(1,1,n,1,n,-1);
	}
}

void solve(){
	cin >> n >> q;
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	build(1,1,n);
	for (int i = 1, k; i <= q; i++){
		cin >> x[i] >> k;
		vx[i].resize(k);
		for (int& it: vx[i]) cin >> it;
		node_query[x[i]].push_back(i);
	}
	dfs2(1,0);
	
	for (int i = 1; i <= q; i++) cout << res[i] << "\n";
	
	
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

