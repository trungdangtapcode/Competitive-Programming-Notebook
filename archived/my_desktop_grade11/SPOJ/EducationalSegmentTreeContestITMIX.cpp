#include <bits/stdc++.h>

using namespace std;

int n, lazy[400005], mul[400005], add[400005], ass[400005], a[100005], val[400005];
const int p = 1e9+7;
int m, op, l, r, x;

//void build(int k, int l, int r){
//	mul[k] = 1;
//	if (l==r){
//		lazy[k] = a[l];
//		return;
//	}
//	int m = (l+r)/2;
//	build(2*k,l,m);
//	build(2*k+1,m+1,r);
//	lazy val
//}

void down(int k, int l, int r, int m){ //ass -> mul -> add
	if (ass[k]){
		val[2*k] = 1ll*ass[k]*(m-l+1)%p;
		val[2*k+1] = 1ll*ass[k]*(r-m)%p;
		ass[2*k] = ass[2*k+1] = ass[k];
		mul[2*k] = mul[2*k+1] = 1;
		add[2*k] = add[2*k+1] = 0;
		ass[k] = 0;
//		return;
	}
	
	val[2*k] = (1ll*val[2*k]*mul[k]+1ll*add[k]*(m-l+1))%p;
	val[2*k+1] = (1ll*val[2*k+1]*mul[k]+1ll*add[k]*(r-m))%p;
	
	mul[2*k] = 1ll*mul[2*k]*mul[k]%p;
	mul[2*k+1] = 1ll*mul[2*k+1]*mul[k]%p;
	add[2*k] = (1ll*add[2*k]*mul[k]+add[k])%p;
	add[2*k+1] = (1ll*add[2*k+1]*mul[k]+add[k])%p;
	mul[k] = 1;
	add[k] = 0;
}

void build(int k, int l, int r){
	mul[k] = 1;
	if (l==r){
		val[k] = a[l];
		return;
	}
	int m = (l+r)/2; 
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = (val[2*k]+val[2*k+1])%p;
}
void updateAss(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] = 1ll*x*(r-l+1)%p;
		ass[k] = x;
		mul[k] = 1;
		add[k] = 0;
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	updateAss(2*k,l,m,u,v,x);
	updateAss(2*k+1,m+1,r,u,v,x);
	val[k] = (val[2*k]+val[2*k+1])%p;
}
void updateMul(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] = 1ll*val[k]*x%p; //not pow
		mul[k] = (1ll*mul[k]*x)%p;
		add[k] = (1ll*add[k]*x)%p;
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	updateMul(2*k,l,m,u,v,x);
	updateMul(2*k+1,m+1,r,u,v,x);
	val[k] = (val[2*k]+val[2*k+1])%p;
}
void updateAdd(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] = (val[k]+1ll*x*(r-l+1))%p;
		add[k] = (add[k]+x)%p;
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	updateAdd(2*k,l,m,u,v,x);
	updateAdd(2*k+1,m+1,r,u,v,x);
	val[k] = (val[2*k]+val[2*k+1])%p;
}
int getSum(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	down(k,l,r,m);
	return (getSum(2*k,l,m,u,v)+getSum(2*k+1,m+1,r,u,v))%p;
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	//freopen("testin.txt", "r", stdin);
	//freopen("test.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	
	//updateAdd(1,1,n,1,n,5);
	//cout << getSum(1,1,n,2,n);
	while (m--){
		cin >> op >> l >> r;
		if (op==1){
			cin >> x;
			updateAdd(1,1,n,l,r,x);
		} else if (op==2){
			cin >> x;
			updateMul(1,1,n,l,r,x);
		} else if (op==3){
			cin >> x;
			updateAss(1,1,n,l,r,x);
		} else {
			cout << getSum(1,1,n,l,r) << '\n';
		}
	}
	
	//for (int i = 0; i <= 4*n; i++) mul[i] = 1;
	
	return 0;
}
