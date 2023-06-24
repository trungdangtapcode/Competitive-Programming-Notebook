#include<bits/stdc++.h>

using namespace std;
int n, a[100005], m, op, pos, v, l, r, k, tmp;
multiset<int> val[400005]; //not vector or sett
void build(int k, int l, int r){
	if (l==r){
//		val[k].push_back(a[l]);
		val[k].insert(a[l]);
		//val[k] = {a[l]}; //(int)1e9}
		return;
	}
	int m = (l+r)/2; 
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = val[2*k]; val[k].insert(val[2*k+1].begin(),val[2*k+1].end());
	//val[k].insert(1e9);
//	val[k] = val[2*k]; val[k].insert(val[k].end(),val[2*k+1].begin(),val[2*k+1].end());
//	sort(val[k].begin(),val[k].end());
//	val[k].resize(unique(val[k].begin(),val[k].end())-val[k].begin());
//	val[k].push_back(1e9);
}

void update(int k, int l, int r, int pos, int x, int y){
	if (pos<l||pos>r) return;
	val[k].erase(val[k].find(y));
	val[k].insert(x);
	if (l==r) return;
	int m = (l+r)/2;
	update(2*k,l,m,pos,x,y);
	update(2*k+1,m+1,r,pos,x,y);
}

int getMin(int k, int l, int r, int u, int v, int x){
	if (u>r||v<l) return 1e9;
	if (u<=l&&r<=v) return *val[k].lower_bound(x);//(val[lower_bound(val[k].begin(),val[k].end(),x)-val[k].begin()]);
	int m = (l+r)/2;
	return min(getMin(2*k,l,m,u,v,x),getMin(2*k+1,m+1,r,u,v,x));
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	for (int i = 1; i <= 4*n; i++) val[i].insert(1e9);
	while (m--){
		cin >> op;
		if (op==1){
			cin >> pos >> v;
			update(1,1,n,pos,v,a[pos]);
			a[pos] = v;
		} else {
			cin >> l >> r >> k;
			tmp = getMin(1,1,n,l,r,k);
			cout << (tmp<1e9?tmp:-1) << '\n';
		}
	}
	return 0; //28/2
}
