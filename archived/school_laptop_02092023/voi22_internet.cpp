#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

using namespace std;

struct Point{
	int x, y, idx;
	int sum_xy(){
		return x+y;
	}
	int diff_yx(){
		return y-x;
	}
};
int dist(Point& a, Point& b){
//	cout << a.x << " " << a.y << " " << b.x << " " << b.y << " => "<< abs(a.x-b.x)+abs(a.y-b.y) << endl;
	return abs(a.x-b.x)+abs(a.y-b.y);
}
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n, k, s;
vector<Point> node;
vector<iii> edgelist;

vector<Point> solve_recur(vector<Point> p){
	if (p.size()<=1) return p;
	auto upper = solve_recur({p.begin(),p.begin()+p.size()/2});
	auto lower = solve_recur({p.begin()+p.size()/2,p.end()});
	vector<Point> res;
	Point min_diff_yx{0,(int)1e9,-1};
	int upper_ptr = 0;
	for (auto lo: lower){
		while (upper_ptr<upper.size()&&upper[upper_ptr].sum_xy()<=lo.sum_xy()){
			if (min_diff_yx.diff_yx()>upper[upper_ptr].diff_yx()) min_diff_yx = upper[upper_ptr];
			res.push_back(upper[upper_ptr]);
			++upper_ptr;
		}
		if (min_diff_yx.idx!=-1) edgelist.push_back({dist(min_diff_yx,lo),{min_diff_yx.idx,lo.idx}});
		res.push_back(lo);
	}
	res.insert(res.end(),upper.begin()+upper_ptr,upper.end());
	return res;
}



void solve_single(vector<Point> p){
	sort(p.begin(),p.end(),[](Point a, Point b){
		return (a.y==b.y?a.x<b.x:a.y>b.y);
	});
	solve_recur(p);
}

void rotate(){
	for (int i = 0; i < n; i++) tie(node[i].x,node[i].y) = make_tuple(node[i].y,-node[i].x);
}
void flip(){
	for (int i = 0; i < n; i++) node[i].x = -node[i].x;
}

int cha[100005], sz[100005];
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
int hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	if (sz[pv]<sz[pu]) swap(pu,pv);
	cha[pu] = pv;
	sz[pv] += sz[pu];
	return true;
}


main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("INTERNET.INP","r",stdin);
//	freopen("INTERNET.OUT","w",stdout);
	cin >> n >> s >> k;
	node.assign(n,Point());	
	for (int i = 0; i < n; i++){
		cin >> node[i].x >> node[i].y;
		node[i].idx = i;
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 2; j++){
			solve_single(node);
			flip();
		}
		rotate();
	}
	sort(edgelist.begin(),edgelist.end());
	edgelist.erase(unique(edgelist.begin(),edgelist.end()),edgelist.end());
	for (int i = 0; i < n; i++) cha[i] = i, sz[i] = 1;
	long long int res = 0;
	for (auto it: edgelist){
//		cout << it.second.first << " -> " << it.second.second << "  c = " << it.first<< "\n";
		if (hop(it.second.first,it.second.second)&&it.first>s&&k) res += it.first, k--;
	}
	cout << res;
	
	return 0;
}
