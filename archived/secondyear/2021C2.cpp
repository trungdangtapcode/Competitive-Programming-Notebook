#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
const string ans[] = {"TIDAK","YA"};
int n, m, q, a[maxN], b[maxN], inva[maxN];
set<int> s[maxN];
struct Node{
	int l = 1e9, r = -1, isOk = 1;
	Node operator+(Node& other){
		Node res;
		res.l = min(l,other.l);
		res.r = max(r,other.r);
//		cout << (isOk&&other.isOk&&(r==other.l-1)) << ".\n";
		res.isOk = isOk&&other.isOk;
		if (r!=-1&&other.r!=-1) res.isOk &= (r==other.l-1);
		return res;
	}
	void print(){
		cout << "l = " << l << " r = " << r << " isOk = " << isOk << "\n"; 
	}
} val[maxN*4];
bool isFirst[maxN];
void flip(int k, int l, int r, int u, int y){
//	cout << k << " " << l << " " << r << "\n";
	if (l>u||r<u) return;
	if (l==r){
		isFirst[u] ^= 1;
		if (isFirst[u]) assert(y!=-1);
		else assert(y==-1);
		val[k].l = y;
		val[k].r = y;
		val[k].isOk = 1;
		return;
	}
	int m = (l+r)/2;
	flip(2*k,l,m,u,y);
	flip(2*k+1,m+1,r,u,y);
	val[k] = val[2*k]+val[2*k+1];
//	val[2*k].print();
//	val[k].print();
}
void solve(){
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		inva[a[i]] = i;
	}
	for (int i = 1; i <= m; i++){
		cin >> b[i];
		b[i] = inva[b[i]];
		s[b[i]].insert(i);
	}
	for (int i = 1; i <= 4*m; i++) val[i] = Node();
	for (int i = 1; i <= m; i++){
		int tmp = (i==*s[b[i]].begin());
		if (tmp) flip(1,1,m,i,b[i]);
	}
//	cout << val[1].isOk << "\n";
//	CANT COMBINE :(, cout << (Node()+Node()).isOk << "\n";
	cout << ans[val[1].isOk] << "\n";
	for (int i = 1; i <= q; i++){
//		cout << i << "\n";
		int qs, qt, tmp1 = 0, tmp2 = 0; cin >> qs >> qt;
//		for (int i = 1; i <= m; i++) cout << isFirst[i] << " "; cout << "\n"; 
		if (qs==*s[b[qs]].begin()) flip(1,1,m,qs,-1), tmp1 = 1;
		s[b[qs]].erase(qs);
		if (s[b[qs]].size()&&tmp1) flip(1,1,m,*s[b[qs]].begin(),b[*s[b[qs]].begin()]);
		b[qs] = inva[qt];
		tmp2 = !s[b[qs]].size()||qs<*s[b[qs]].begin();
		if (tmp2) flip(1,1,m,*s[b[qs]].begin(),-1);
		s[b[qs]].insert(qs);
		if (qs==*s[b[qs]].begin()) flip(1,1,m,qs,b[qs]);
		cout << ans[val[1].isOk] << "\n";
//		for (int i = 1; i <= m; i++) cout << isFirst[i] << " "; cout << "\n"; 
	}
	exit(0);
}

int32_t main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

