#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5, inf = 1e16;
//struct node{
//	int x;
//} val[maxN*4];
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<ii> edge[maxN*4];
int n, q, s, val[maxN*4], idx[maxN], d[maxN*4][2], res[maxN];
void build(int k, int l, int r){
	if (l==r){
		idx[l] = k;
		val[k] = l;		
		return;
	}
	val[k] = -1;
	int m = (l+r)/2;
	edge[k].push_back({2*k,0});
	edge[k].push_back({2*k+1,0});
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	edge[2*k].push_back({k,0});
	edge[2*k+1].push_back({k,0});
}
void updt(int k, int l, int r, int u, int v, int x, int w, int rev){
	if (l>v||r<u) return;
//	cout << k << " " << l << ".." << r << "\n";
	if (u<=l&&r<=v){
//		cout << k << " -> " << x << "\n";
		if (rev) edge[x].push_back({k,w});
		else edge[k].push_back({x,w});
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,v,x,w,rev);
	updt(2*k+1,m+1,r,u,v,x,w,rev);
}

main(){
	cin >> n >> q >> s;
	build(1,1,n);
	for (int i = 0; i < q; i++){
		int t, u, v, l, r, w;
		cin >> t;
		if (t==1){
			cin >> u >> v >> w;
			edge[idx[u]].push_back({idx[v],w});
		} else {
			cin >> u >> l >> r >> w;
			updt(1,1,n,l,r,idx[u],w,(t==2));
		}
	}
	for (int i = 1; i <= 4*n; i++) d[i][0] = d[i][1] = inf;
	int u = idx[s];
	d[u][0] = d[u][1] = 0;
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0,{0,u}});
	pq.push({0,{1,u}});
	while (pq.size()){
		int u = pq.top().second.second, app = pq.top().second.first; pq.pop();
		for (ii it: edge[u]){
			int v = it.first, c = it.second, appv = app;
			if (c!=0) appv = 1;
			if (u/2==v&&c==0) appv = 0;
			if (app==0&&v/2==u&&c==0) continue;
			if (d[v][appv]>d[u][app]+c){
				d[v][appv] = d[u][app]+c;
				pq.push({d[v][appv],{appv,v}});
			}
		}
	}
//	for (int i = 1; i <= n*4; i++) cout << i << "." << val[i] << " = "<< d[i][0] << ", " <<d[i][1] << "\n";
	for (int i = 1; i<= n; i++) res[i] =  min(d[idx[i]][0],d[idx[i]][1]);
	for (int i = 1; i <= n; i++) cout << (res[i]==inf?-1:res[i]) << " ";
//	for (int i = 1; i<= n; i++) cout << min(d[idx[i]][0],d[idx[i]][1]) << " ";
	
	return 0;
}
