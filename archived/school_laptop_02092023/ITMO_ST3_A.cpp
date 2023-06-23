#include<bits/stdc++.h>

using namespace std;

int val[400005], n, m, a[100005];
void updt(int k, int l, int r, int x, int y){
	if (l>x||r<x) return;
	if (l==x&&r==x){
		val[k] += y;
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
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cout << gett(1,1,n,a[i]+1,n) << " ";
		updt(1,1,n,a[i],1);
	}
	
	return 0;
}
