#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 2e5+5, T = 470;
int cha[maxN], comp, sz[maxN], rk[maxN];
int ans = 0;
//multiset<int> ms;

int n, m, q, u[maxN], v[maxN], a[maxN], res[maxN];

struct Plan{
	int l, r, idx;
	Plan(int _l = 0, int _r = 0, int _idx = 0){
		l = _l;
		r = _r;
		idx = _idx;
	}
} plan[maxN];

struct Query{
	int u, v, szu, szv, rku, rkv, shot, ans;
	Query(int _u = 0, int _v = 0, int _szu = 0, int _szv = 0,
	 int _rku = 0, int _rkv = 0, int _shot = 0, int _ans = 0){
		u = _u;
		v = _v;
		szu = _szu;
		szv = _szv;
		rku = _rku;
		rkv = _rkv;
		shot = _shot;
		ans = _ans;
	}
} sta[maxN];

int pos = 0;
struct CCBM{
	void push(Query x){
		sta[pos++] = x;
	}
	Query top(){
		return sta[pos-1];
	}
	void pop(){
		pos--;
	}
	int size(){
		return pos;
	}
	bool empty(){
		return pos==0;
	}
} query;

void init(){
//	ms.clear();
	ans = 0;
	for (int i = 1; i <= n; i++) cha[i] = i, sz[i] = a[i], rk[i] = 1, ans = max(ans,a[i]);//, ms.insert(a[i]);
	comp = n;
	while (query.size()) query.pop();
}
int timcha(int x){
	return cha[x]==x?x:timcha(cha[x]);
}
void hop(int u, int v){
	u = timcha(u);
	v = timcha(v);
	if (u==v) return;
	if (rk[u]<rk[v]) swap(u,v);
	cha[v] = u;
	query.push(Query(u,v,sz[u],sz[v],rk[u],rk[v],0,ans));
	sz[u] += sz[v];
	if (rk[u]==rk[v]) rk[u]++;
	ans = max(ans,sz[u]);
//	ms.erase(ms.find(sz[u]));
//	ms.erase(ms.find(sz[v]));
//	ms.insert(sz[u]);
	comp--;
}
void rollback(){
	while (query.size()&&query.top().shot==0){
		auto it = query.top(); query.pop();
		cha[it.u] = it.u;
		cha[it.v] = it.v;
		sz[it.u] = it.szu;
		sz[it.v] = it.szv;
		rk[it.u] = it.rku;
		rk[it.v] = it.rkv;
//		ms.erase(ms.find(it.szu+it.szv));
//		ms.insert(it.szu);
//		ms.insert(it.szv);
		ans = it.ans;
		comp++;
	}
	assert(query.size());
	if (query.size()) query.pop();
}

void solve(){ 
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> u[i] >> v[i];
	for (int i = 1; i <= q; i++) cin >> plan[i].l >> plan[i].r;
	for (int i = 1; i <= q; i++) plan[i].idx = i;
	sort(plan+1,plan+q+1,[](Plan x, Plan y){
		if (x.l/T!=y.l/T){
			return x.l<y.l;
		}
		return x.r < y.r;
	});
	int last_block = -1;
	for (int i = 1, l = -1, r = -1; i <= q; i++){
//		cout << " query " << plan[i].l << ".." << plan[i].r << "\n";
		int block = plan[i].l/T;
		if (last_block != block){
			init();
			l = (block+1)*T, r = l;
			last_block = block;
		}
		for (; r <= plan[i].r; r++) hop(u[r], v[r]);
		query.push(Query(-1,-1,-1,-1,-1,-1,1,-1));
		for (int j = plan[i].l; j < min(l,plan[i].r+1); j++) hop(u[j], v[j]);
//		cout << plan[i].idx << " = "; for (int i: ms) cout << i << " "; cout << '\n';
		res[plan[i].idx] = ans;//*ms.rbegin();
		rollback();
		assert(plan[i].r>=l||query.empty());
//		cout << "sz = " << query.size() << "\n";
//		break;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

