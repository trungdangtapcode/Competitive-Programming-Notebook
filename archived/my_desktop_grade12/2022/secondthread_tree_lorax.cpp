#include<bits/stdc++.h>

using namespace std;

long long val[100005];
int n, q;
void reset(){
	fill(val,val+n+1,0);
}
void updt(int x, int v){
	for (; x <= n; x += x&-x) val[x] += v;
}
long long gett(int x){
	long long res = 0;
	for (; x > 0; x -= x&-x)  res += val[x];
	return res;
}

vector<int> edge[100005];
int timer, par[100005], tin[100005], tout[100005];
void dfs(int p,int u){
	tin[u] = ++timer;
	par[u] = p;
	for (int v: edge[u]) if (p!=v) dfs(u,v);
	tout[u] = timer;
}

void solve(){
	cin >> n >> q;
	reset();
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	timer = 0; dfs(0,1);
	while (q--){
		int x, a, b;
		cin >> a >> b >> x;
		if (x){
			updt(tin[a],x);
			updt(tin[b],-x);
		} else {
			if (par[a]==b) swap(a,b);
			long long inside = gett(tout[b]) - gett(tin[b]-1);
//			outside = gett(n)-inside;
			cout << abs(inside) << "\n";
		}
	}	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ntest; cin >> ntest;
	while (ntest--) solve();
	return 0;
}
