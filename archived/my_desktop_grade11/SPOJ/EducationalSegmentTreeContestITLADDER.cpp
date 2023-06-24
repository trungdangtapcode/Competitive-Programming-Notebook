#include <bits/stdc++.h>

using namespace std;
int n, q, a[100005], val[400005], lazy1[400005], lazy2[400005], sum1[400005], sum2[400005];
const int p = 1e9+7;

void build(int k, int l, int r){
	if (l==r){
		val[k] = a[l];
		sum1[k] = l;
		sum2[k] = 1;
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = (val[2*k]+val[2*k+1])%p;
	sum1[k] = (sum1[2*k]+sum1[2*k+1])%p;
	sum2[k] = (sum2[2*k]+sum2[2*k+1])%p;
//	cout << l << " " << r << "=>" << sum1[k] << " " << sum2[k] << '\n';
}
void down(int k){
	val[2*k] = (val[2*k] + 1ll*sum1[2*k]*lazy1[k] + 1ll*sum2[2*k]*lazy2[k])%p;
	val[2*k+1] = (val[2*k+1] + 1ll*sum1[2*k+1]*lazy1[k] + 1ll*sum2[2*k+1]*lazy2[k])%p;
	lazy1[2*k] = (lazy1[2*k] + lazy1[k])%p;
	lazy2[2*k] = (lazy2[2*k] + lazy2[k])%p;
	lazy1[2*k+1] = (lazy1[2*k+1] + lazy1[k])%p;
	lazy2[2*k+1] = (lazy2[2*k+1] + lazy2[k])%p;
	lazy1[k] = lazy2[k] = 0;
}
void update(int k, int l, int r, int u, int v, int x, int y){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] = (val[k] + 1ll*sum1[k]*x - 1ll*u*x*sum2[k] + 1ll*y*sum2[k])%p;
		lazy1[k] = (lazy1[k] + x)%p;
		lazy2[k] = (lazy2[k] - 1ll*u*x + y)%p;
		return;
	}
	down(k);
	int m = (l+r)/2;
	update(2*k,l,m,u,v,x,y);
	update(2*k+1,m+1,r,u,v,x,y);
	val[k] = (val[2*k]+val[2*k+1])%p;
}
int getSum(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return val[k];
	down(k);
	int m = (l+r)/2;
	return (getSum(2*k,l,m,u,v)+getSum(2*k+1,m+1,r,u,v))%p;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	//for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	
	int op, l, r, x, y;
	while (q--){
		cin >> op >> l >> r;
		if (op==1){
			cin >> x >> y;
			update(1,1,n,l,r,x,y);
		} else {
			cout << (getSum(1,1,n,l,r)%p+p)%p << '\n';
		}
	}
	
	return 0;
}
