#include <bits/stdc++.h>

using namespace std;
int n, x, y, q, a[50005], s[50005];
int mmax[200005], mmin[200005], sum[200005];
int return_mmax[200005], return_mmin[200005], return_sum[200005];

void build(int k, int l, int r){
	if (l==r){
		mmax[k] = s[l];
		mmin[k] = s[l-1];
		sum[k] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	mmax[k] = max(mmax[2*k],mmax[2*k+1]);
	mmin[k] = min(mmin[2*k],mmin[2*k+1]);
	sum[k] = max({sum[2*k],sum[2*k+1],mmax[2*k+1]-mmin[2*k]});
}
void getMax(int k, int l, int r, int u, int v){
	if (u>r||v<l) {
		return_mmax[k] = -1e9;
		return_mmin[k] = 1e9;
		return_sum[k] = -1e9;
		return;
	}
	if (u<=l&&r<=v){
		return_mmax[k] = mmax[k];
		return_mmin[k] = mmin[k];
		return_sum[k] = sum[k];
		return;
	}
	int m = (l+r)/2;
	getMax(2*k,l,m,u,v);
	getMax(2*k+1,m+1,r,u,v);
	return_mmax[k] = max(return_mmax[2*k],return_mmax[2*k+1]);
	return_mmin[k] = min(return_mmin[2*k],return_mmin[2*k+1]);
	return_sum[k] = max({return_sum[2*k],return_sum[2*k+1],return_mmax[2*k+1]-return_mmin[2*k]});
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	build(1,1,n);
	
	cin >> q;
	while (q--){
		cin >> x >> y;
		getMax(1,1,n,x,y);
		cout << return_sum[1] << '\n';
	}
	return 0;
}
