#include<bits/stdc++.h>

using namespace std;
int n, m, q, u, v, x;
long long int lazy[400005], val[400005];

void down(int k, int l, int r, int m){
	long long int t = lazy[k];
	if (t==0) return;
	val[2*k] = (m-l+1)*t;
	val[2*k+1] = (r-m)*t;
	lazy[2*k] = lazy[2*k+1] = t;
	lazy[k] = 0;
}

void updt(int k, int l, int r, int u, int v, int x){
	if (v<l||u>r) return;
	if (u<=l&&r<=v){
		val[k] = (r-l+1)*x;
		lazy[k] = x;
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = val[2*k] + val[2*k+1];
}

long long int gett(int k, int l, int r, int u, int v){
	if (v<l||u>r) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	down(k,l,r,m);
	return gett(2*k,l,m,u,v)+gett(2*k+1,m+1,r,u,v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("tongdaycon.inp","r",stdin);
	freopen("tongdaycon.out","w",stdout);
	cin >> n >> m;
	while (m--){
		cin >> q >> u >> v;
		if (q==0){
			cin >> x;
			updt(1,1,n,u,v,x);
		} else {
			cout << gett(1,1,n,u,v) << "\n";
		}
	}
	
	return 0;
}
