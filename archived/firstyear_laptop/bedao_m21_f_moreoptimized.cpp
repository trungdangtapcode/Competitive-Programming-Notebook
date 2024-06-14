#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], val[maxN*4][4], valb[maxN*4][2];
char c[maxN];
const int nxt[] = {0,1,3,2}, pos[] = {0,1,3,2};

void merge(int k, int x, int y, bool leaf = 0){
	if (!leaf) for (int i = 0; i < 4; i++){
		val[k][i] = val[x][i]+val[y][nxt[(pos[i]+val[x][i])%4]];
	}
	if (!leaf) for (int i = 0; i < 2; i++) valb[k][i] = valb[x][i]||valb[y][i];
	if (leaf) val[k][0] = val[k][1] = valb[k][0],val[k][2] = val[k][3] = valb[k][1];
}

void build(int k, int l, int r){
	if (l==r){
		valb[k][a[l]] = 1;
		valb[k][a[l]^1] = 0;
		merge(k,-1,-1,1);
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	merge(k,2*k,2*k+1);
}

void updt(int k, int l, int r, int u){
	if (l>u||r<u) return;
	if (l==r){
		valb[k][a[l]] = 1;
		valb[k][a[l]^1] = 0;
		merge(k,-1,-1,1);
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u);
	updt(2*k+1,m+1,r,u);
	merge(k,2*k,2*k+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		a[i] = c[i] - '0';
	};
	build(1,1,n);
	
	int q; cin >> q;
	while (q--){
		int u; cin >> u;
		a[u] ^= 1;
		updt(1,1,n,u);
		int res = (valb[1][0]||valb[1][1]);
//		for (int i = 0; i < 4; i++) cout << val[1][i] << "\n";
		for (int l = 0; l < 4; l++) res = max(res,val[1][l]);
		cout << res << "\n";
	}
	
	return 0;
}

