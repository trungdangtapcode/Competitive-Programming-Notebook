#include<bits/stdc++.h>

using namespace std;
#define int long long
int val[400005], n, m, op, u, v, x, lazy[400005];
void down(int k, int l, int r, int m){
	val[2*k] += lazy[k]*(m-l+1);
	val[2*k+1] += lazy[k]*(r-m);
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	lazy[k] = 0; 
}
void updt(int k, int l, int r, int u, int v, int x){
	if (u>r||l>v) return;
	if (u<=l&&r<=v){
		val[k] += (r-l+1)*x;
		lazy[k] += x;
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = (val[2*k]+val[2*k+1]);
}
int gett(int k, int l, int r, int u){
	if (r<u||l>u) return 0;
	if (l==r) return val[k];
	int m = (l+r)/2;
	down(k,l,r,m);
	return gett(2*k,l,m,u)+gett(2*k+1,m+1,r,u);
}


main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> m;
//	for (int i = 0, x; i < n; i++){
//		cin >> x;
//		updt(1,0,n-1,i,i,x);
//	}
	while (m--){
		cin >> op;
		if (op==1){
			cin >> u >> v >> x;
			updt(1,0,n-1,u,v-1,x);
		} else {
			cin >> u;
			cout << gett(1,0,n-1,u) << "\n";
		}
	}
	
	return 0;
}
