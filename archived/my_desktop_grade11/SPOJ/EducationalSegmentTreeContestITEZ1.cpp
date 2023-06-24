#include <bits/stdc++.h>

using namespace std;
int n, q, p, a[100005];
int val[400005];


void buildTree(int k, int l, int r){
	if (l==r) {
		val[k] = a[l];
		return;
	}
	
	int m = (l+r)/2;
	buildTree(2*k,l,m);
	buildTree(2*k+1,m+1,r);
	val[k] = max(val[2*k],val[2*k+1]);
}

void updateTree(int k, int l, int r, int x, int y){
//	if (l==r) {
//		if (l==x) val[k] = y; 
//	}
//	if (l > x|| r < x) return;
	if (l==r) {
		val[k] = y;
		return;
	}
	int m = (l+r)/2;
	if (x<=m) updateTree(2*k,l,m,x,y); else updateTree(2*k+1,m+1,r,x,y);
	val[k] = max(val[2*k],val[2*k+1]);
}

int INF = 1e9+5;
int getTree(int k, int l, int r, int u, int v){
	if (l>v||r<u) return -INF;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return max(getTree(2*k,l,m,u,v),getTree(2*k+1,m+1,r,u,v));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> q;
	buildTree(1,1,n);
	
	//for (int i = 1; i <= 4*n; i++) cout << i << ". " << val[i] << endl;
	while (q--){
		int x, a, b;
		cin >> x >> a >> b;
		if (x==1){
			updateTree(1,1,n,a,b);
		} else{
			cout << getTree(1,1,n,a,b) << '\n';
		}
	}
	
	return 0;
}
