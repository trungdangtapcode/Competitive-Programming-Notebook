#include<bits/stdc++.h>

using namespace std;
int val[2000005], lazyAssign[2000005], lazyAND[2000005];
int n, q;
const int fll = (1<<30)-1;
//Assign then ADD
void down(int k, int m, int l, int r){
	if (lazyAssign[k]==-1&&lazyAND[k]==fll) return;
	if (lazyAssign[k]!=-1) lazyAssign[2*k] = lazyAssign[2*k+1] = val[2*k] = val[2*k+1] = lazyAssign[k], lazyAND[2*k] = lazyAND[2*k+1] = fll;
	lazyAND[2*k] &= lazyAND[k];
	lazyAND[2*k+1] &= lazyAND[k];
	val[2*k] &= lazyAND[k];
	val[2*k+1] &= lazyAND[k];
	lazyAssign[k] = -1;
	lazyAND[k] = fll;
}
void updateAND(int k, int l, int r, int u, int v, int x){
	if (l>v||u>r) return;
	if (u<=l&&r<=v){
		val[k] = val[k]&x;
		lazyAND[k] &= x;
		return;
	}
	int m = (l+r)/2;	
	down(k,m,l,r);
	updateAND(2*k,l,m,u,v,x);
	updateAND(2*k+1,m+1,r,u,v,x);
	val[k] = val[2*k]|val[2*k+1];
}
void updateAssign(int k, int l, int r, int u, int v, int x){
	if (l>v||u>r) return;
	if (u<=l&&r<=v){
		val[k] = x;
		lazyAssign[k] = x;
		lazyAND[k] = fll;
		return;
	}
	int m = (l+r)/2;
	down(k,m,l,r);
	updateAssign(2*k,l,m,u,v,x); //Assign ma goi updateAND =))
	updateAssign(2*k+1,m+1,r,u,v,x);
	val[k] = val[2*k]|val[2*k+1];
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||u>r) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	down(k,m,l,r);
	return gett(2*k,l,m,u,v)|gett(2*k+1,m+1,r,u,v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= 4*n; i++) val[i] = fll, lazyAND[i] = fll, lazyAssign[i] = -1;
	for (int i =1, a; i <= n; i++){
		cin >> a;
		updateAssign(1,1,n,i,i,a);
	} 		
	while (q--){
		int op, l, r, x;
		cin >> op >> l >> r;
		if (op==1){
			cin >> x;
			updateAND(1,1,n,l,r,x);
		} else if (op==2){
			cin >> x;
			updateAssign(1,1,n,l,r,x);
		} else cout << gett(1,1,n,l,r) << "\n";
//		for (int i = 1; i<= n; i++) cout << gett(1,1,n,i,i) << " "; cout << "[]\n";
	}
	
	return 0;
}
