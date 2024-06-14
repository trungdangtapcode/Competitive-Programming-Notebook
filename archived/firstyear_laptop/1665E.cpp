#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
typedef pair<int,int> ii;
int n, q, a[maxN];
ii val[4*maxN];

void updt(int k, int l, int r, int u, int x){
	if (r<u||l>u) return;
	if (l==r){
		val[k] = {x,u};
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,x);
	updt(2*k+1,m+1,r,u,x);
	val[k] = min(val[2*k],val[2*k+1]);
}
ii gett(int k,int l,int r, int u, int v){
	if (l>v||r<u) return {2e9, -1};
	if (u<=l&&r<=v){
		return val[k];
	}
	int m = (l+r)/2;
	return min(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i<= n; i++){
		updt(1,1,n,i,a[i]);
	}
	cin >> q;
	for (int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		vector<ii> vec;
		for (int j = 0; j < min(r-l+1,30); j++){
			ii tmp =gett(1,1,n,l,r);
			vec.push_back(tmp);
//			cout << tmp.first << ".." << tmp.second << "\n";
			updt(1,1,n,tmp.second, 2e9);
		}
		int res = 2e9;
		for (auto it1: vec) for (auto it2: vec) if (it1.second!=it2.second){
			int cur = it1.first|it2.first;
			res = min(res,cur);
		}
		cout << res << "\n";	
		for (auto it: vec){
			updt(1,1,n,it.second,it.first);
		}
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

