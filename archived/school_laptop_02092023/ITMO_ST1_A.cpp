#include<bits/stdc++.h>

using namespace std;
int n, m, o, x, y;
long long val[400005];
void updt(int k, int l, int r, int x, int v){
	if (r<x||l>x) return;
	if (x==l&&x==r){
		val[k] = v;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,x,v);
	updt(2*k+1,m+1,r,x,v);
	val[k] = (val[2*k] + val[2*k+1]);
}
long long gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return gett(2*k,l,m,u,v)+gett(2*k+1,m+1,r,u,v);
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		updt(1,1,n,i,a);
	}
	while (m--){
		cin >> o >> x >> y;
		if (o==1){
			updt(1,1,n,x+1,y);
		} else cout << gett(1,1,n,x+1,y) << "\n";
	}
	
	return 0;
}
