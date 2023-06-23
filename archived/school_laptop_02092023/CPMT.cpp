#pragma GCC optimize("O3")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
int a[205][205], x[205], y[205], val[1005], n, m;
long long int pref[205];
void build(int k, int l, int r){
	if (l==r){
		val[k] = x[l];
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = __gcd(val[2*k],val[2*k+1]);
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||u>r) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return __gcd(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	long long int res = 1e12;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) x[j] = 0, y[j] = 0;
		for (int j = i; j <= n; j++){
			for (int k = 1; k <= m; k++) x[k] = __gcd(x[k],a[j][k]), y[k] += a[j][k], pref[k] = pref[k-1]+y[k];
			build(1,1,m);
			for (int k1 = 1, k2 = 1; k1 <= m; k1++){
				while (k2<m&&gett(1,1,m,k1,k2)!=1) k2++;
				if (gett(1,1,m,k1,k2)==1) res = min(res,pref[k2]-pref[k1-1]);
			}
		}
	}
	cout << res;
	
	
	return 0;
}
