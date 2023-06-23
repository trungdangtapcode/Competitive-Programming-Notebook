#include<bits/stdc++.h>

using namespace std;
int f[105][15], a[200005], val[800005], n, q;
int sum_digits(int x){
	int res = 0;
	while (x){
		res += x%10;
		x/= 10;
	}
	return res;
}
void updt(int k, int l, int r, int u, int v){
	if (u>r||l>v) return;
	if (u<=l&&r<=v){
		val[k]++;
		return;
	}
	val[2*k] += val[k];
	val[2*k+1] += val[k];
	val[k] = 0;
	int m = (l+r)/2;
	updt(2*k,l,m,u,v);
	updt(2*k+1,m+1,r,u,v);
}
int gett(int k, int l, int r, int u){
	if (l>u||r<u) return -1;
	if (l==r){
		int t = val[k];
		if (t==0) return a[l];
		if (a[l]>100) a[l] = sum_digits(a[l]), t--;
		a[l] = f[a[l]][min(10,t)];
		val[k] = 0;
		return a[l];
	}
	val[2*k] += val[k];
	val[2*k+1] += val[k];
	val[k] = 0;
	int m = (l+r)/2;
	return max(gett(2*k,l,m,u),gett(2*k+1,m+1,r,u));
}

main(){
	for (int i = 1; i <= 100; i++){
		f[i][0] = i;
		for (int j = 1; j <= 10; j++){
			f[i][j] = sum_digits(f[i][j-1]);
		}
	}
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> q;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= 4*n; i++) val[i] = 0;
		while (q--){
			int t, l, r;
			cin >> t;
			if (t==1){
				cin >> l >> r;
				updt(1,1,n,l,r);
			} else {
				cin >> l;
				cout << gett(1,1,n,l) << "\n";
			}
		}
	}
	
	return 0;
}
