#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii> a;
int val[4000005], lazy[4000005], n;

void down(int k){
	if (lazy[k]==0) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	val[2*k] += lazy[k];
	val[2*k+1] += lazy[k];
	lazy[k] = 0;
}

void updt(int k,int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] += x;
		lazy[k] += x;
		return;
	}
	int m = (l+r)/2;
	down(k);
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = max(val[2*k],val[2*k+1]);
}

main(){
	cin >> n;
	a.assign(n,{{0,0},0});
	for (int i = 0; i < n; i++){
		cin >> a[i].first.second >> a[i].first.first >> a[i].second;
	}
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i++) swap(a[i].first.first,a[i].first.second);
	int res = 0;
	for (int i = 0; i < n; i++){
		updt(1,1,1e6,1,a[i].first.first,a[i].second);
		if (i==n-1||i<n-1&&a[i].first.second!=a[i+1].first.second) res = max(res,val[1]);
		//res = max(res,val[1]); van AC??!
	}
	cout << res;
	
	return 0;
}
