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
	val[k] = max(val[2*k],val[2*k+1]);
}
int findd(int k, int l, int r, int x, int lb){
//	cout << l << " " << r << " " << x << " " << val[k] << endl;
	if (val[k]<x||r<lb) return 1e9;
	if (l==r) return l-1;
	int m = (l+r)/2;
	if (lb<=l) if (val[2*k]>=x) return findd(2*k,l,m,x,lb); else return findd(2*k+1,m+1,r,x,lb);
	else return min(findd(2*k,l,m,x,lb),findd(2*k+1,m+1,r,x,lb));
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		updt(1,1,n,i,a[i]);
	}
	int op, x, y;
	while (m--){
		cin >> op;
		if (op==1){
			cin >> x >> y;
			x++;
			updt(1,1,n,x,y);
		} else {
			cin >> x >> y;
			y++;
			int tmp = findd(1,1,n,x,y);
			cout << (tmp==1e9?-1:tmp) << "\n";
		}
	}
	
	return 0;
}
