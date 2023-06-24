#include<bits/stdc++.h>

using namespace std;
#define int long long
int val[400005], n, m, a[100005];
void build(int k, int l, int r){
	if (l==r){
		val[k] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = (val[2*k]+val[2*k+1]);
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return gett(2*k,l,m,u,v) + gett(2*k+1,m+1,r,u,v);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1,1,n);
	while (m--){
		int l, r;
		cin >> l >> r;
		cout << gett(1,1,n,l,r) << "\n";
	}
	
	return 0;
}
