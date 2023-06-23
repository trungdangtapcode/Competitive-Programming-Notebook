#include<bits/stdc++.h>

using namespace std;

int val[400005], n, m, a[100005];
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
int findd(int k, int l, int r, int x){
//	cout << l << " " << r << " " << x << " " << val[k] << endl;
//	if (val[k]<x||x<1) return -1;
	if (l==r) return l;
	int m = (l+r)/2;
//	return max(findd(2*k,l,m,x),findd(2*k+1,m+1,r,x-val[2*k]));
	if (x<=val[2*k]) return findd(2*k,l,m,x); else return findd(2*k+1,m+1,r,x-val[2*k]);
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		updt(1,1,n,i,a[i]);
	}
	int x, y;
	while (m--){
		cin >> x >> y;
		y++;
		if (x==1){
			updt(1,1,n,y,a[y]=!a[y]);
		} else {
			cout << findd(1,1,n,y)-1 << "\n";
		}
	}
	
	return 0;
}
