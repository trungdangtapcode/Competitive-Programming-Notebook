#include<bits/stdc++.h>

using namespace std;

int tin[200005], tout[200005], timer, val[800005], n, m, a[200005];
vector<int> edge[200005];
int d[200005];
void dfs(int p, int u){
	tin[u] = ++timer;
	d[tin[u]] = -d[tin[p]];
	for (auto v: edge[u]) if (p!=v){
		dfs(u,v);
	}
	tout[u] = timer;
}
void updt(int k, int l, int r, int u, int v, int x){
	if (u>r||v<l) return;
	if (u<=l&&r<=v){
		val[k] += x;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
}
int gett(int k, int l, int r, int u){
	if (l>u||r<u) return 0;
	if (l==r) return val[k];
	int m = (l+r)/2;
	return gett(2*k,l,m,u)+gett(2*k+1,m+1,r,u)+val[k];
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	d[0] = -1;
	dfs(0,1);
	for (int i = 1; i <= n; i++) updt(1,1,n,tin[i],tin[i],a[i]*d[tin[i]]);
//	for (int i = 1; i <= n; i++) cout << gett(1,1,n,tin[i])*d[tin[i]] << " "; cout << endl;
//	updt(1,1,n,tin[1],tout[1],10);
//	for (int i = 1; i <= n; i++) cout << gett(1,1,n,tin[i])*d[tin[i]] << " "; cout << endl;
//	for (int i = 1; i <= n; i++) cout << i << " " << tin[i] << ".." << tout[i] << " " << d[tin[i]]<< "\n";
	for (int i = 1, o, x, val; i <= m; i++){
		cin >> o >> x;
		if (o==1){
			cin >> val;
			updt(1,1,n,tin[x],tout[x],val*d[tin[x]]);
		} else cout << gett(1,1,n,tin[x])*d[tin[x]] << "\n";
	};
//	updt(1,1,n,1,n,5);
//	updt(1,1,n,1,2,4);
//	cout << gett(1,1,n,3);
	
	return 0;
}
