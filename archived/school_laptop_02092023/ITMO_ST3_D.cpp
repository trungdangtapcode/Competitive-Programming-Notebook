#include<bits/stdc++.h>

using namespace std;
int val[800005], n, m, res[100005], prv[200005], a[200005];
void updt(int k, int l, int r, int x, int y){
	if (l>x||r<x) return;
	if (l==x&&r==x){
		val[k] = y;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,x,y);
	updt(2*k+1,m+1,r,x,y);
	val[k] = val[2*k] + val[2*k+1];
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v){
		return val[k];
	}
	int m = (l+r)/2;
	return gett(2*k,l,m,u,v)+gett(2*k+1,m+1,r,u,v);
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= 2*n; i++) updt(1,1,2*n,i,0);
	for (int i = 1; i <= n; i++) prv[i] = -1;
	for (int i = 1, x; i <= 2*n; i++){
		cin >> a[i];
		x = a[i];
		if (prv[x]==-1){
			prv[x] = i;
			continue;
		}
		if (prv[x]!=-1){
			res[x] += gett(1,1,2*n,prv[x],i);
			updt(1,1,2*n,i,1);
			updt(1,1,2*n,prv[x],-1);
		}
	}
	for (int i = 1; i <= 2*n; i++) updt(1,1,2*n,i,0);
	for (int i = 1; i <= n; i++) prv[i] = -1;
	for (int i = 2*n, x; i >= 1; i--){
		x = a[i];
		if (prv[x]==-1){
			prv[x] = i;
			continue;
		}
		if (prv[x]!=-1){
			res[x] += gett(1,1,2*n,i,prv[x]); //+=
			updt(1,1,2*n,i,1);
			updt(1,1,2*n,prv[x],-1);
		}
	}
	
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
	
	return 0;
}
