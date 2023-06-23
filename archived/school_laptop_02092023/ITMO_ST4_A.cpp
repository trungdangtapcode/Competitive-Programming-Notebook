#include<bits/stdc++.h>

using namespace std;
const int sgn[] = {-1,1};
int val[400005], n, m, op, u, v, x;
void updt(int k, int l, int r, int u, int x){
	if (u>r||l>u) return;
	if (l==r){
		val[k] = sgn[l%2]*x;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,x);
	updt(2*k+1,m+1,r,u,x);
	val[k] = (val[2*k]+val[2*k+1]);
}
int gett(int k, int l, int r, int u, int v){
	if (r<u||l>v) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return gett(2*k,l,m,u,v)+gett(2*k+1,m+1,r,u,v);
}


main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 1, x; i <= n; i++){
		cin >> x;
		updt(1,1,n,i,x);
	}
	cin >> m;
	while (m--){
		cin >> op >> u >> v;
		if (op==0){
			updt(1,1,n,u,v);
		} else {
			cout << sgn[u%2]*gett(1,1,n,u,v) << "\n";
		}
	}
	
	return 0;
}
