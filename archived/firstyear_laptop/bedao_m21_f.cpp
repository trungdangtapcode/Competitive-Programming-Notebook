#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], val[maxN*4][4][4], valb[maxN*4][2];
char c[maxN];
//00 01 10 11 0 1
//R0-L3 R3-L0 R1-L2 R2-L1
//L [R-L] R -> LR
const int dx[] = {0,3,1,2}, dy[] = {3,0,2,1};
const int addl[2][4] = {{-1,0,-1,1},{2,-1,3,-1}}, addr[2][4] = {{-1,-1,0,2},{1,3,-1,-1}};

int merge(int k, int x, int y){
	for (int l = 0; l < 4; l++) for (int r = 0; r < 4; r++){
		int &res = val[k][l][r];
		res = max(val[x][l][r],val[y][l][r]);
		for (int i = 0; i < 4; i++) if (val[x][l][dx[i]]&&val[y][dy[i]][r])
			res = max(res,val[x][l][dx[i]]+val[y][dy[i]][r]);
	}
	if (valb[y][0]) for (int l = 0; l < 4; l++) for (int r = 0; r < 4; r++) if (addr[0][r]!=-1&&val[x][l][r])
		val[k][l][addr[0][r]] = max(val[k][l][addr[0][r]],val[x][l][r]+1);
//	if (valb[y][0]) for (int l = 0; l < 4; l++) for (int r = 0; r < 4; r++) if (addr[0][r]!=-1)
//		cout << "hi";
	if (valb[y][1]) for (int l = 0; l < 4; l++) for (int r = 0; r < 4; r++) if (addr[1][r]!=-1&&val[x][l][r])
		val[k][l][addr[1][r]] = max(val[k][l][addr[1][r]],val[x][l][r]+1);
	if (valb[x][0]) for (int l = 0; l < 4; l++) for (int r = 0; r < 4; r++) if (addl[0][l]!=-1&&val[y][l][r])
		val[k][addl[0][l]][r] = max(val[k][addl[0][l]][r],val[y][l][r]+1);
	if (valb[x][1]) for (int l = 0; l < 4; l++) for (int r = 0; r < 4; r++) if (addl[1][l]!=-1&&val[y][l][r])
		val[k][addl[1][l]][r] = max(val[k][addl[1][l]][r],val[y][l][r]+1);
	for (int i = 0; i < 2; i++) valb[k][i] = valb[x][i] + valb[y][i];
//	if (valb[k][0]>1) for (int i = 0; i < 4; i++)
//		val[k][0][0] = max(val[k][0][0],2),
	if (valb[k][0]>1) val[k][0][0] = max(val[k][0][0],2); 
//	if (valb[k][1]>1) for (int i = 0; i < 4; i++)
//		val[k][3][3] = max(val[k][3][3],2),
	if (valb[k][1]>1) val[k][3][3] = max(val[k][3][3],2);
	if (valb[x][0]&&valb[y][1]) val[k][1][1] = max(val[k][1][1],2);
	if (valb[x][1]&&valb[y][0]) val[k][2][2] = max(val[k][2][2],2);
}

void build(int k, int l, int r){
	if (l==r){
		valb[k][a[l]] = 1;
		valb[k][a[l]^1] = 0;
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
//	cout << val[1][0][0] << " " << valb[3][0];
//	for (int l = 0; l < 4; l++) for (int r = 0; r < 4; r++){
//		cout << l << " " << r << " = " << val[1][l][r] << "\n";
//	}
//	return 0;
	
	int q; cin >> q;
	while (q--){
		int u; cin >> u;
		a[u] ^= 1;
		updt(1,1,n,u);
		int res = (valb[1][0]||valb[1][1]);
		for (int l = 0; l < 4; l++) for (int r = 0; r < 4; r++) res = max(res,val[1][l][r]);
		cout << res << "\n";
	}
	
	return 0;
}


//R00 R01 R10 R11 L_ ... 0 1
///0-3, 1-2, 2-1, 3-0
//=> 0-7, 1-6, 2-5, 3-4 (ans)
//0: 77
//1: 78
//2: 87
//3: 88
