#include<bits/stdc++.h>

using namespace std;
#define ll long long
int n, m;
ll p;

struct mat{
	ll a[2][2] = {{0,0},{0,0}};
	mat operator*(mat b){
		mat res;
		res.a[0][0] = (a[0][0]*b.a[0][0]+a[0][1]*b.a[1][0])%p;
		res.a[0][1] = (a[0][0]*b.a[0][1]+a[0][1]*b.a[1][1])%p;
		res.a[1][0] = (a[1][0]*b.a[0][0]+a[1][1]*b.a[1][0])%p;
		res.a[1][1] = (a[1][0]*b.a[0][1]+a[1][1]*b.a[1][1])%p;
//		cout << a[0][0] << " " << a[0][1] << " " << a[1][0] << " " << a[1][1] << " }\n";
		return res;
	}
};
mat a[200005], val[800005];
mat mat1;
void build(int k, int l, int r){
	if (l==r){
		val[k] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = val[2*k]*val[2*k+1];
}
mat gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return mat1;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return gett(2*k,l,m,u,v)*gett(2*k+1,m+1,r,u,v);
}
ostream& operator<<(ostream &os, mat x){
	return os << x.a[0][0] << " " << x.a[0][1] << "\n" << x.a[1][0] << " " << x.a[1][1] << "\n\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	mat1.a[0][0] = mat1.a[1][1] = 1;
	cin >> p >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i].a[0][0] >> a[i].a[0][1] >> a[i].a[1][0] >> a[i].a[1][1];
	}
	
	build(1,1,n);
	while (m--){
		int u, v;
		cin >> u >> v;
		cout << gett(1,1,n,u,v);
	}
//	cout << val[1].a[0][0] << " " << val[1].a[0][1] << "\n" << val[1].a[1][0] << " " << val[1].a[1][1]; 
	
	return 0;
}
