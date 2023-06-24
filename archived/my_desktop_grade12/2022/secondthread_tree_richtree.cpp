#include<bits/stdc++.h>

using namespace std;
int n, q;
vector<int> edge[300005];
long double val[300005];

void reset(){
	for (int i = 1; i <= n; i++) val[i] = 0;
}
void updt(int x, long double v){
	for (; x <= n; x += x&-x) val[x] += v;
}
long double gett(int x){
	long double res = 0;
	for (; x > 0; x -= x&-x) res += val[x];
	return res;
}
long double query(int l, int r){
	return gett(r)-gett(l-1);
}
int timer, tin[300005], tout[300005];
void dfs(int p, int u){
	tin[u] = ++timer;
	for (int v: edge[u]) if (v!=p) dfs(u,v);
	tout[u] = timer;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	reset();
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}	
	dfs(0,1);
	cout << fixed << setprecision(9);
	cin >> q;
	while (q--){
		int t, x, y;
		cin >> t >> x >> y;
		long double tmp = log10(y);
		if (t==1){
			updt(tin[x],-query(tin[x],tin[x]));
			updt(tin[x],tmp);
		} else {
			long double res = query(tin[x],tout[x])-query(tin[y],tout[y]);
			res = pow(10,res);
			if (res>1e9) cout << "1000000000\n";
			else cout << res << "\n";
		}
	}
	
	
	return 0;
}
