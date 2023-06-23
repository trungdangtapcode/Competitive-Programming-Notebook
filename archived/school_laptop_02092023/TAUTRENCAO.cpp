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

typedef pair<int,int> ii;
int lazy[800005], val[800005], n, m, c, sz;
vector<ii> a;
vector<int> v;
void down(int k, int l, int r, int m){
	if (lazy[k]==0) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	val[2*k] += lazy[k];
	val[2*k+1] += lazy[k];
	lazy[k] = 0;
}
void updt(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] += x;
		lazy[k] += x;
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = max(val[2*k],val[2*k+1]);
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	down(k,l,r,m);
	return max(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c >> m;
	a.assign(n,{0,0});
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
		v.push_back(a[i].second);
		v.push_back(a[i].first);
	}
	sort(a.begin(),a.end(),[](ii a, ii b){
		if (a.second==b.second) return a.first>b.first;
		else return a.second<b.second;
	});
//	for (int i = 0; i < n; i++) swap(a[i].first,a[i].second);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int sz = v.size();
	for (int i = 0; i < n; i++){
//		cout << i  << " < " << n<< endl;
		a[i].first = lower_bound(v.begin(),v.end(),a[i].first)-v.begin()+1;
		a[i].second = lower_bound(v.begin(),v.end(),a[i].second)-v.begin()+1;
//		cout << "{" << a[i].first << " , " << a[i].second << "}\n";
	}
	int res = 0;
	for (int i = 0; i < n; i++){
		int tmp = gett(1,1,sz,a[i].first,a[i].second);
		if (gett(1,1,sz,a[i].first,a[i].second)>gett(1,1,sz,a[i].first+1,a[i].second)&&gett(1,1,sz,a[i].first+1,a[i].second)<c){
			res++;
			updt(1,1,sz,a[i].first+1,a[i].second,1);
		} else if (gett(1,1,sz,a[i].first,a[i].second)<c){
			res++;
			updt(1,1,sz,a[i].first,a[i].second,1);
		}
//		for (int j = 1; j <= sz; j++) cout << gett(1,1,sz,j,j) << " "; cout << endl;
	}
	cout << res;
	
	
	
	
	return 0;
}
