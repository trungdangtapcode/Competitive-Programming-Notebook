/*
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;	
int n, val[maxN*4][3], lazy[4*maxN], m, l[maxN], r[maxN], k;

void build(int k, int l, int r){
	if (l==r){
		val[k][0] = 1;
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k][0] = val[k*2][0] + val[2*k+1][0];
}
//void build2(int k, int l, int r, int x){
//	updt(1,1,n,dl[x],dr[x],)
//	if (l>dr[x]||r<dl[x]) return;
//	if (dl[x]<=l&&r<=dr[x]){
//		node[k].push_back(x);
//		return;
//	}
//	int m = (l+r)/2;
//	build2(2*k,l,m,x);
//	build2(2*k+1,m+1,r,x);
//}
void down(int k){
	if (lazy[k]==0) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	if (lazy[k]>0){
		for (int i = 2; i >= lazy[k]; i--) val[2*k][i] = val[2*k][i-lazy[k]];
		for (int i = 0; i < lazy[k]; i++) val[2*k][i] = 0;
	}
	else {
		for (int i = 0; i <= 2-lazy[k]; i++) val[2*k+1][i] = val[2*k+1][i+lazy[k]];
		for (int i = 2-lazy[k]+1; i <= 2; i++) val[2*k+1][i] = 0;
	}
	if (lazy[k]>0){
		for (int i = 2; i >= lazy[k]; i--) val[2*k+1][i] = val[2*k+1][i-lazy[k]];
		for (int i = 0; i < lazy[k]; i++) val[2*k+1][i] = 0;
	}
	else {
		for (int i = 0; i <= 2-lazy[k]; i++) val[2*k][i] = val[2*k][i+lazy[k]];
		for (int i = 2-lazy[k]+1; i <= 2; i++) val[2*k][i] = 0;
	}
	lazy[k] = 0;
}
void updt(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
//		cout << l << ".." << r << " "<< x << "\n";
		if (x==1){
			for (int i = 2; i > 0; i--) val[k][i] = val[k][i-1];
			val[k][0] = 0; 
		} else {
			for (int i = 0; i <= 1; i++) val[k][i] = val[k][i+1];
			val[k][2] = 0;
		};
		lazy[k] += x;
//		cout << val[k][1] << "\n";
		return;
	}
	down(k);
	int m = (l+r)/2;
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	for (int i = 0; i <= 2; i++) val[k][i] = val[2*k][i] + val[2*k+1][i];
}
int query(int k, int l, int r, int u, int v){
//	cout << l << r << "\n";
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return val[k][1];
	down(k);
	int m = (l+r)/2;
	return query(2*k,l,m,u,v) + query(2*k+1,m+1,r,u,v);
}
void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> l[i] >> r[i];
	for (int i = 1; i <= 4*n; i++) val[i][0] = val[i][1] = val[i][2] = 0;
	build(1,1,n);
	for (int i = 1; i <= m; i++) updt(1,1,n,l[i],r[i],1);
//	for (int i = 1; i <= n; i++) cout << query(1,1,n,i,i);
	for (int i = 1; i <= m; i++){
		int c = query(1,1,n,l[i],r[i]);
		
	}
}

main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
*/
