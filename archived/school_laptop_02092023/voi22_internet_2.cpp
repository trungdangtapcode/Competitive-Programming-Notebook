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
	int x, y, idx, yy;
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
vector<int> vec;

ii val[1000005];
void reset(){
	for (int i = 1; i <= 1e6; i++) val[i] = {-1e9,-1};
}
void them(int x, ii y){
	for (; x <= 1e6; x += (x&-x)) val[x] = max(val[x],y);
}
int gett(int x){
	ii res = {-1e9,-1};
	for (; x > 0; x -= (x&-x)) res = max(res,val[x]);
	return res.second;
}

void solve_single(vector<Point> p){ //phai xuong 45 do
	sort(p.begin(),p.end(),[](Point a, Point b){
		return (a.sum_xy()==b.sum_xy()?a.x>b.x:a.sum_xy()>b.sum_xy());
	});
	reset();
	for (auto it: p){
		int x = gett(it.yy);
		if (x!=-1){
			edgelist.push_back({dist(it,node[x]),{it.idx,x}});
		}
		them(it.yy,{it.diff_yx(),it.idx});
	}
	
}

void rotate(){
	for (int i = 0; i < n; i++) tie(node[i].x,node[i].y) = make_tuple(node[i].y,-node[i].x);
	for (int i = 0; i < n; i++) node[i].yy = lower_bound(vec.begin(),vec.end(),node[i].y)-vec.begin()+1;
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
		vec.push_back(node[i].y);
		vec.push_back(node[i].x);
		vec.push_back(-node[i].y);
		vec.push_back(-node[i].x);
		node[i].idx = i;
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for (int i = 0; i < n; i++) node[i].yy = lower_bound(vec.begin(),vec.end(),node[i].y)-vec.begin()+1;
//	solve_single(node);
//	for (auto it: edgelist) cout << it.second.first << " -> " << it.second.second << endl;
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
