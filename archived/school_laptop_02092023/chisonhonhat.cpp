#include<bits/stdc++.h>

using namespace std;
int val[400005], n, q, p, u, x;
void updt(int k, int l, int r, int u, int x){
	if (u<l||r<u) return;
	if (l==r){
		val[k] = x;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,x);
	updt(2*k+1,m+1,r,u,x);
	val[k] = min(val[2*k],val[2*k+1]);
}
int gett(int k, int l, int r, int x){
	if (l==r) return l;
	int m = (l+r)/2;
	if (val[2*k]<=x) return gett(2*k,l,m,x);
	else if (val[2*k+1]<=x) return gett(2*k+1,m+1,r,x);
	else return -1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("chisonhonhat.inp","r",stdin);
	freopen("chisonhonhat.out","w",stdout);
	
	cin >> n >> q;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		updt(1,1,n,i,a);
	}
	while (q--){
		cin >> p;
		if (p){
			cin >> x;
			cout << gett(1,1,n,x) << "\n";
		} else {
			cin >> u >> x;
			updt(1,1,n,u,x);
		}
	}
	
	
	return 0;
}
