#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m, o, x, y;
ii val[400005];
void updt(int k, int l, int r, int x, int v){
	if (r<x||l>x) return;
	if (x==l&&x==r){
		val[k] = {v,1};
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,x,v);
	updt(2*k+1,m+1,r,x,v);
	val[k] = min(val[2*k],val[2*k+1]);
	if (val[2*k].first==val[2*k+1].first) val[k].second = val[2*k].second+val[2*k+1].second;
}
ii gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return {1e9,-1};
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	ii tmp1 = gett(2*k,l,m,u,v), tmp2 = gett(2*k+1,m+1,r,u,v), tmp;
	tmp = min(tmp1,tmp2);
	if (tmp1.first==tmp2.first) tmp.second = tmp1.second+tmp2.second;
	return tmp;
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
		} else cout << gett(1,1,n,x+1,y).first << " " << gett(1,1,n,x+1,y).second << "\n";
	}
	
	return 0;
}
