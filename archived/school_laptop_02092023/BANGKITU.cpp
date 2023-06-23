#include<bits/stdc++.h>
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

using namespace std;

int val[120005], n, m, sum, a[4005][4005], k;
void reset(){
	memset(val,1,sizeof(val));
//	for (int i = 0; i <= 4*m; i++) val[i] = 1e9;
}
void updt(int k, int l, int r, int u, int v){
	if (l>u||r<u) return;
	if (l==r){
		val[k] = min(val[k],v);
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,v);
	updt(2*k+1,m+1,r,u,v);
	val[k] = min(val[2*k],val[2*k+1]);
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 1e9;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return min(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++){
			string s;
			cin >> s;
			for (int j = 1; j <= m; j++) a[i][j] = (s[j-1]=='A'?1:-1);
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++) a[i][j] += a[i-1][j];
		}
		
		long long int res = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
	//			i = 1, j = 2;
				reset();
				updt(1,1,n*m,0+n*m/2,0);
				int sum = 0;
				for (int l = 1; l <= m; l++){
					sum += a[j][l]-a[i-1][l];
					res = max(res,1ll*(l-gett(1,1,n*m,sum-k+n*m/2,sum+k+n*m/2))*(j-i+1));
					updt(1,1,n*m,sum+m*n/2,l);
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}
