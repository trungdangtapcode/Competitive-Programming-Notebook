#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n, q;
long long lazy[400005], val[400005];
void down(int k, int m, int l, int r){
	if (lazy[k]==0) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	val[2*k] += lazy[k]*(m-l+1);
	val[2*k+1] += lazy[k]*(r-m);
	lazy[k] = 0;
}
void updt(int k, int l, int r, int u, int v, int x){
	if (u>r||l>v) return;
	if (u<=l&&r<=v){
		val[k] += 1ll*(r-l+1)*x;
		lazy[k] += x;
		return;
	}
	int m = (l+r)/2;
	down(k,m,l,r);
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = (val[2*k]+val[2*k+1]);
}
long long gett(int k, int l, int r, int u, int v){
	if (u>r||l>v) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	down(k,m,l,r);
	return gett(2*k,l,m,u,v)+gett(2*k+1,m+1,r,u,v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		updt(1,1,n,i,i,a);
	}
	vector<iii> query;
	query.push_back({-1,{-1,-1}});
	while (q--){
		int t, l = -1, r = -1, x = -1, i;
		cin >> t;
		if (t==1){
			cin >> l >> r >> x;
			updt(1,1,n,l,r,x);
		} else if (t==2){
			cin >> i;
			l = query[i].second.first, r = query[i].second.second, x = -query[i].first;
			updt(1,1,n,l,r,x);
		} else {
			cin >> l >> r;
			cout  << gett(1,1,n,l,r) << "\n";
			
		}
		query.push_back({x,{l,r}});
	}
	
	
	return 0;
}
