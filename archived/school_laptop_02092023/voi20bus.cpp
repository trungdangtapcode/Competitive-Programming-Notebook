#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

struct dsu_save{
	int u, v, ur, vr, op;
	dsu_save(int u, int v, int ur, int vr, int op){
		this->u = u;
		this->v = v;
		this->ur = ur;
		this->vr = vr;
		this->op = op;   
	}
};
vector<dsu_save> dsu_list;
int cha[50005], sz[50005], comp;
void reset(int n){
	for (int i = 1; i <= n; i++) cha[i] = i, sz[i] = 1;
	comp = n;
}
int timcha(int x){
	return (cha[x]==x?x:timcha(cha[x]));
}
bool hop(int u, int v){
	u = timcha(u), v = timcha(v);
	if (u==v){
		dsu_list.push_back(dsu_save(u,v,-1,-1,0));
		return false;
	}
	dsu_list.push_back(dsu_save(u,v,sz[u],sz[v],1));
	if (sz[u]>sz[v]) swap(u,v);
	sz[v] += sz[u];
	cha[u] = v;
	comp--;
	return true;
}
void rollback(){
	assert(dsu_list.size());
	if (dsu_list.empty()) return;
	auto it = dsu_list.back(); dsu_list.pop_back();
	int u = it.u, v= it.v, op = it.op, ur = it.ur, vr = it.vr;
	if (!op) return;
	comp++;
	cha[u] = u;
	cha[v] = v;
	sz[u] = ur;
	sz[v] = vr;
}

vector<iii> edgelist[3];
int f[50005], g[50005], s, t;
void dp(int l, int r, int from, int to){
	if (r<l) return;
	int m = (l+r)/2;
	f[m] = from;
	for (int i = max(1,l); i <= m; i++){
		int u = edgelist[1][i].second.first, v = edgelist[1][i].second.second;
		hop(u,v);
	}
	for (int i = from+1; i <= to; i++){
		if (timcha(s)==timcha(t)) break; //not comp == 1 =))))
		int u = edgelist[2][i].second.first, v = edgelist[2][i].second.second;
		hop(u,v);
		f[m] = i;
	}
	g[m] = timcha(s)!=timcha(t);
	for (int i = from+1; i <= f[m]; i++) rollback();
	dp(m+1,r,from,f[m]);
	for (int i = max(1,l); i <= m; i++) rollback();
	for (int i = from+1; i <= f[m]; i++){
		int u = edgelist[2][i].second.first, v = edgelist[2][i].second.second;
		hop(u,v);
	}
	dp(l,m-1,f[m],to);
	for (int i = from+1; i <= f[m]; i++) rollback();
}

int n, m;

int main(){
//	reset(10);
//	hop(1,2);
//	hop(2,3);
//	rollback();
//	rollback();
//	for (int i = 1; i <= 10; i++) cout << timcha(i) << " ";
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	edgelist[1].push_back({(int)-1e9,{-1,-1}});
	edgelist[2].push_back({(int)-1e9,{-1,-1}});
	cin >> n >> m >> s >> t;
	reset(n);
	for (int i = 1; i <= n; i++) f[i] = g[i] = -1;
	for (int i = 0, u, v, c, company; i < m; i++){
		cin >> company >> u >> v >> c;
		edgelist[company].push_back({c,{u,v}});
	}
	sort(edgelist[1].begin(),edgelist[1].end());
	sort(edgelist[2].begin(),edgelist[2].end());
	int szA = edgelist[1].size()-1, szB = edgelist[2].size()-1;
	dp(0,szA,0,szB);
	int res = 2e9+1;
	for (int i = 0; i <= szA; i++){
//		cout<< "A takes " << i << " " << "B takes " << f[i] << "? it's " << (g[i]?"NO\n":"YES\n");
		if (g[i]==1) continue;
		int cur1 = max(0,edgelist[1][i].first);
		int cur2 = max(0,edgelist[2][f[i]].first);
		res = min(res,cur1+cur2);
	}
	cout <<res;
	
	return 0;
}
