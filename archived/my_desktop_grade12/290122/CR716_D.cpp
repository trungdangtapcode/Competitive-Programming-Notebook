#include<bits/stdc++.h>

using namespace std;
int val[1200005], a[300005], n, q;
vector<int> v[300005];
int cnt(int l, int r, int k){
	return upper_bound(v[k].begin(),v[k].end(),r)-lower_bound(v[k].begin(),v[k].end(),l);
}
void build(int k, int l, int r){
	if (l==r){
		val[k] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = (cnt(l,r,val[2*k])>cnt(l,r,val[2*k+1])?val[2*k]:val[2*k+1]);
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||u>r) return 0;
	if (u<=l&&r<=v){
		return cnt(u,v,val[k]);
	}
	int m = (l+r)/2;
	return max(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		v[a[i]].push_back(i);
	};
	build(1,1,n);
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << max(1,2*gett(1,1,n,l,r)-(r-l+1)) << "\n";
	}
	return 0;
}
