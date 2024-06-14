#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5;
int n, lazy[maxN*4], val[maxN*4], a[maxN], q, m;
vector<int> vec[maxN];
void down(int k, int l, int r, int m){
	if (lazy[k]==-1) return;
	lazy[2*k] = lazy[2*k+1] = lazy[k];
	val[2*k] = lazy[k]*(m-l+1);
	val[2*k+1] = lazy[k]*(r-m);
	lazy[k] = -1;
}
void updt(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] = (v-u+1)*x;
		lazy[k] = x;
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = val[2*k] + val[2*k+1];
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	down(k,l,r,m);
	return gett(2*k,l,m,u,v)+gett(2*k+1,m+1,r,u,v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(lazy,-1,sizeof(lazy));
	cin >> m >> q;
	n = q;
	for (int j = 1, i = 1; j <= q; j++){
		int t, x;
		cin >> t >> x;
		if (t==1){
			updt(1,1,n,i,i,1);
			vec[x].push_back(i);
			i++;
		} else if (t==2) {
			for (int y: vec[x]) updt(1,1,n,y,y,0);
			vec[x].clear();
		} else {
//			cout << i-x << " " << i-1 << "\n";
			updt(1,1,n,1,x,0);
//			int f = gett(1)
		}
//		for (int i = 1; i <= n; i++) cout << gett(1,1,n,i,i) << " ";
//		cout << "\n";
		cout << val[1] << "\n";
	}
	
	return 0;
}
