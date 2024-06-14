#include<bits/stdc++.h>

using namespace std;
typedef array<int,20> base;
const int maxN = 2e5+5;
int n, a[maxN], jmp[maxN][20], tin[maxN], tout[maxN];
vector<int> sind[maxN]; //set independ
vector<int> edge[maxN];

void elim(base& b, int& x){ //make it independ
	for (int i = 0; i < 20; i++){
		if ((x>>i)&1) x ^= b[i];
	}
}
bool add(base& b, int x){
	elim(b,x);
	if (x==0) return 0;
	for (int i = 0; i < 20; i++) if ((x>>i)&1){
		b[i] = x;
		return 1;		
	}
}
void print(base& b){
	for (int i = 0; i < 20; i++){
		cout << bitset<20>(b[i]) << "\n";
	}
}
base empty_base(){
	base res;
	for (int i = 0; i < 20; i++) res[i] = 0;
	return res;
}

int timer = 0;
void dfs(int u, int p){
	tin[u] = ++timer;
	jmp[u][0] = p;
	for (int i = 1; i < 20; i++) jmp[u][i] = jmp[jmp[u][i-1]][i-1];
	base tmp = empty_base();
	add(tmp,a[u]); sind[u].push_back(u);
	for (int x: sind[p]) if (add(tmp,a[x])) sind[u].push_back(x);
//	cout << u << ": "; for (int x: sind[u]) cout << x << ", "; cout << "\n";
//	print(tmp);
	for (int v: edge[u]) if (v!=p){
		dfs(v,u);
	}
	tout[u] = timer;
}
bool isChild(int u, int v){ //u is child of v
	if (v==0) return 1;
	return (tin[v]<=tin[u]&&tout[u]<=tout[v]);
}
int lca(int u, int v){
	if (isChild(v,u)) return u;
	for (int i = 19; i >= 0; i--) if (!isChild(v,jmp[u][i])) u = jmp[u][i];
	return jmp[u][0];
}
int solve(int u, int v, int k){
	if (k==0) return 1;
	int z = lca(u,v);
	base b = empty_base();
	for (int x: sind[u]) if (isChild(x,z)) add(b,a[x]);
	for (int x: sind[v]) if (isChild(x,z)) add(b,a[x]);
//	print(b);
//	for (int x: sind[u]) if (isChild(x,z)) cout << x << ", "; cout << "\n";
//	cout << z  << "\n";
	return (!add(b,k));
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
//	cout << "tin: "; for (int i = 1; i <= n; i++) cout << tin[i] << " "; cout <<"\n";
//	cout << "tout: "; for (int i = 1; i <= n; i++) cout << tout[i] << " "; cout << "\n";
	int q; cin >> q;
	while (q--){
		int x, y, k;
		cin >> x >> y >> k;
		cout << (solve(x,y,k)?"YES":"NO") << "\n";
	}
//	base x = empty_base();
//	add(x,3);
//	add(x,2);
//	print(x);
}
