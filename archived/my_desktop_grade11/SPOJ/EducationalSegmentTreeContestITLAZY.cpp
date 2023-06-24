#include <bits/stdc++.h>

using namespace std;
int pref[100005], n, q;
long long int val[400005], lazy[400005];


void buildTree(int k, int l, int r){
	if (l == r) {
		val[k] = pref[l];
		lazy[k] = 0;
		return;
	}
	int m = (l+r)/2;
	buildTree(2*k,l,m);
	buildTree(2*k+1,m+1,r);
	val[k] = max(val[2*k],val[2*k+1]);
	lazy[k] = 0;
}
void downTree(int k){ //not leaf
	if (!lazy[k]) return;
	val[2*k] += lazy[k];
	lazy[2*k] += lazy[k];
	val[2*k+1] += lazy[k];
	lazy[2*k+1] += lazy[k];
	lazy[k] = 0;
}
void updateTree(int k, int l, int r, int u, int v, int x){
	//cout << l << " " << r <<"   "<< u<<" " << v << endl;
	if (v<l||u>r) return;
	if (u <= l && r <= v){
		val[k] += x;
		lazy[k] += x;
		return;
	}
	downTree(k); //update
	
	int m = (l+r)/2;
	updateTree(2*k,l,m,u,v,x);
	updateTree(2*k+1,m+1,r,u,v,x);
	val[k] = max(val[2*k],val[2*k+1]);
}
long long int INF = 1e16+5;
long long int getTree(int k, int l, int r, int u, int v){
	if (l>v||r<u) return -INF;
	if (u<=l&&r<=v) return val[k];
	downTree(k);
	
	int m = (l+r)/2;
	return max(getTree(2*k,l,m,u,v),getTree(2*k+1,m+1,r,u,v));
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> pref[i];
	buildTree(1,1,n);
	cin >> q;
	
	while (q--){
		int x;
		cin >> x;
		if (x == 1){
			int u, v, val;
			cin >> u >> v >> val;
			updateTree(1,1,n,u,v,val);
		} else {
			int u, v;
			cin >> u >> v;
			cout << getTree(1,1,n,u,v)<<'\n';
		}
	}
	
	
	return 0;
}
