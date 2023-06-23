#include<bits/stdc++.h>

using namespace std;

int val[40000005], lazy[4000005], n, m;

void down(int k){
	if (lazy[k]==0) return;
	lazy[4*k-2] += lazy[k];
	lazy[4*k-1] += lazy[k];
	lazy[4*k+0] += lazy[k];
	lazy[4*k+1] += lazy[k];
	val[4*k-2] += lazy[k];
	val[4*k-1] += lazy[k];
	val[4*k+0] += lazy[k];
	val[4*k+1] += lazy[k];
	lazy[k] = 0;
}
void updt(int k, int lx, int ly, int rx, int ry, int ux, int uy, int vx, int vy, int x){
	if (ux>rx||uy>ry||vx<lx||vy<ly) return;
	if (ux<=lx&&rx<=vx&&uy<=ly&&ry<=vy){
		val[k] += x;
		lazy[k] += x;
		return;
	}
	int mx = (lx+rx)/2, my = (ly+ry)/2;
	down(k);
	updt(4*k-2,lx,ly,mx,my,ux,uy,vx,vy,x);
	updt(4*k-1,mx+1,ly,rx,my,ux,uy,vx,vy,x);
	updt(4*k+0,lx,my+1,mx,ry,ux,uy,vx,vy,x);
	updt(4*k+1,mx+1,my+1,rx,ry,ux,uy,vx,vy,x);
	val[k] = max({val[4*k-2],val[4*k-1],val[4*k+0],val[4*k+1]});
}
int gett(int k, int lx, int ly, int rx, int ry, int ux, int uy, int vx, int vy){
	if (ux>rx||uy>ry||vx<lx||vy<ly) return -1e9;
	if (ux<=lx&&rx<=vx&&uy<=ly&&ry<=vy) return val[k];
	int mx = (lx+rx)/2, my = (ly+ry)/2;
	down(k);
	return max({gett(4*k-2,lx,ly,mx,my,ux,uy,vx,vy),
	gett(4*k-1,mx+1,ly,rx,my,ux,uy,vx,vy),
	gett(4*k+0,lx,my+1,mx,ry,ux,uy,vx,vy),
	gett(4*k+1,mx+1,my+1,rx,ry,ux,uy,vx,vy)});
}

int a[1000005][6], q;
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1, x; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> x;
			updt(1,1,1,n,m,i,j,i,j,x);
		};
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++) cout << gett(1,1,1,n,m,i,j,i,j) << " ";
//		cout << endl;
//	}	
	cin >> q;
	int tmp = q;
	while (q--){
		cin >> a[q][0] >> a[q][1] >> a[q][2] >> a[q][3] >> a[q][4];
		updt(1,1,1,n,m,a[q][0],a[q][1],a[q][2],a[q][3],a[q][4]);
//		for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++) cout << gett(1,1,1,n,m,i,j,i,j) << " ";
//			cout << endl;
//		}	
	}
	int res = 1e9;
	for (int i = 0; i < tmp; i++){
//		cout << a[i][0] << " " << a[i][1] << " " <<a[i][2] << " " << a[i][3] << " -" << a[i][4] << endl;
		updt(1,1,1,n,m,a[i][0],a[i][1],a[i][2],a[i][3],-a[i][4]);
//		for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++) cout << gett(1,1,1,n,m,i,j,i,j) << " ";
//			cout << endl;
//		}		
//		cout << val[1] << endl;
		res = min(res,val[1]);
		updt(1,1,1,n,m,a[i][0],a[i][1],a[i][2],a[i][3],a[i][4]);
	}
	cout <<res;
	
	return 0;
}
